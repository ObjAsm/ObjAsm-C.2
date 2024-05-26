;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\mmreg.h
;             Created on (UTC) 22/05/2024 17:57:07
;             Last modified on (UTC) 12/02/2024 17:05:50

include winapifamily.inc
if  not Defined(__midl)
  ifndef _INC_MMREG
    _INC_MMREG equ 158
    if _MSC_VER gt 1000
    endif
    if  not Defined(RC_INVOKED) and Defined(_MSC_VER)
      if (_MSC_VER le 800)
      else
        include pshpack1.inc
      endif
    endif
    ifdef __cplusplus
      ;[...]
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ifndef NOMMIDS
        ifndef MM_MICROSOFT
          MM_MICROSOFT equ 1
        endif
        MM_CREATIVE equ 2
        MM_MEDIAVISION equ 3
        MM_FUJITSU equ 4
        MM_PRAGMATRAX equ 5
        MM_CYRIX equ 6
        MM_PHILIPS_SPEECH_PROCESSING equ 7
        MM_NETXL equ 8
        MM_ZYXEL equ 9
        MM_BECUBED equ 10
        MM_AARDVARK equ 11
        MM_BINTEC equ 12
        MM_HEWLETT_PACKARD equ 13
        MM_ACULAB equ 14
        MM_FAITH equ 15
        MM_MITEL equ 16
        MM_QUANTUM3D equ 17
        MM_SNI equ 18
        MM_EMU equ 19
        MM_ARTISOFT equ 20
        MM_TURTLE_BEACH equ 21
        MM_IBM equ 22
        MM_VOCALTEC equ 23
        MM_ROLAND equ 24
        MM_DSP_SOLUTIONS equ 25
        MM_NEC equ 26
        MM_ATI equ 27
        MM_WANGLABS equ 28
        MM_TANDY equ 29
        MM_VOYETRA equ 30
        MM_ANTEX equ 31
        MM_ICL_PS equ 32
        MM_INTEL equ 33
        MM_GRAVIS equ 34
        MM_VAL equ 35
        MM_INTERACTIVE equ 36
        MM_YAMAHA equ 37
        MM_EVEREX equ 38
        MM_ECHO equ 39
        MM_SIERRA equ 40
        MM_CAT equ 41
        MM_APPS equ 42
        MM_DSP_GROUP equ 43
        MM_MELABS equ 44
        MM_COMPUTER_FRIENDS equ 45
        MM_ESS equ 46
        MM_AUDIOFILE equ 47
        MM_MOTOROLA equ 48
        MM_CANOPUS equ 49
        MM_EPSON equ 50
        MM_TRUEVISION equ 51
        MM_AZTECH equ 52
        MM_VIDEOLOGIC equ 53
        MM_SCALACS equ 54
        MM_KORG equ 55
        MM_APT equ 56
        MM_ICS equ 57
        MM_ITERATEDSYS equ 58
        MM_METHEUS equ 59
        MM_LOGITECH equ 60
        MM_WINNOV equ 61
        MM_NCR equ 62
        MM_EXAN equ 63
        MM_AST equ 64
        MM_WILLOWPOND equ 65
        MM_SONICFOUNDRY equ 66
        MM_VITEC equ 67
        MM_MOSCOM equ 68
        MM_SILICONSOFT equ 69
        MM_TERRATEC equ 70
        MM_MEDIASONIC equ 71
        MM_SANYO equ 72
        MM_SUPERMAC equ 73
        MM_AUDIOPT equ 74
        MM_NOGATECH equ 75
        MM_SPEECHCOMP equ 76
        MM_AHEAD equ 77
        MM_DOLBY equ 78
        MM_OKI equ 79
        MM_AURAVISION equ 80
        MM_OLIVETTI equ 81
        MM_IOMAGIC equ 82
        MM_MATSUSHITA equ 83
        MM_CONTROLRES equ 84
        MM_XEBEC equ 85
        MM_NEWMEDIA equ 86
        MM_NMS equ 87
        MM_LYRRUS equ 88
        MM_COMPUSIC equ 89
        MM_OPTI equ 90
        MM_ADLACC equ 91
        MM_COMPAQ equ 92
        MM_DIALOGIC equ 93
        MM_INSOFT equ 94
        MM_MPTUS equ 95
        MM_WEITEK equ 96
        MM_LERNOUT_AND_HAUSPIE equ 97
        MM_QCIAR equ 98
        MM_APPLE equ 99
        MM_DIGITAL equ 100
        MM_MOTU equ 101
        MM_WORKBIT equ 102
        MM_OSITECH equ 103
        MM_MIRO equ 104
        MM_CIRRUSLOGIC equ 105
        MM_ISOLUTION equ 106
        MM_HORIZONS equ 107
        MM_CONCEPTS equ 108
        MM_VTG equ 109
        MM_RADIUS equ 110
        MM_ROCKWELL equ 111
        MM_XYZ equ 112
        MM_OPCODE equ 113
        MM_VOXWARE equ 114
        MM_NORTHERN_TELECOM equ 115
        MM_APICOM equ 116
        MM_GRANDE equ 117
        MM_ADDX equ 118
        MM_WILDCAT equ 119
        MM_RHETOREX equ 120
        MM_BROOKTREE equ 121
        MM_ENSONIQ equ 125
        MM_FAST equ 126
        MM_NVIDIA equ 127
        MM_OKSORI equ 128
        MM_DIACOUSTICS equ 129
        MM_GULBRANSEN equ 130
        MM_KAY_ELEMETRICS equ 131
        MM_CRYSTAL equ 132
        MM_SPLASH_STUDIOS equ 133
        MM_QUARTERDECK equ 134
        MM_TDK equ 135
        MM_DIGITAL_AUDIO_LABS equ 136
        MM_SEERSYS equ 137
        MM_PICTURETEL equ 138
        MM_ATT_MICROELECTRONICS equ 139
        MM_OSPREY equ 140
        MM_MEDIATRIX equ 141
        MM_SOUNDESIGNS equ 142
        MM_ALDIGITAL equ 143
        MM_SPECTRUM_SIGNAL_PROCESSING equ 144
        MM_ECS equ 145
        MM_AMD equ 146
        MM_COREDYNAMICS equ 147
        MM_CANAM equ 148
        MM_SOFTSOUND equ 149
        MM_NORRIS equ 150
        MM_DDD equ 151
        MM_EUPHONICS equ 152
        MM_PRECEPT equ 153
        MM_CRYSTAL_NET equ 154
        MM_CHROMATIC equ 155
        MM_VOICEINFO equ 156
        MM_VIENNASYS equ 157
        MM_CONNECTIX equ 158
        MM_GADGETLABS equ 159
        MM_FRONTIER equ 160
        MM_VIONA equ 161
        MM_CASIO equ 162
        MM_DIAMONDMM equ 163
        MM_S3 equ 164
        MM_DVISION equ 165
        MM_NETSCAPE equ 166
        MM_SOUNDSPACE equ 167
        MM_VANKOEVERING equ 168
        MM_QTEAM equ 169
        MM_ZEFIRO equ 170
        MM_STUDER equ 171
        MM_FRAUNHOFER_IIS equ 172
        MM_QUICKNET equ 173
        MM_ALARIS equ 174
        MM_SICRESOURCE equ 175
        MM_NEOMAGIC equ 176
        MM_MERGING_TECHNOLOGIES equ 177
        MM_XIRLINK equ 178
        MM_COLORGRAPH equ 179
        MM_OTI equ 180
        MM_AUREAL equ 181
        MM_VIVO equ 182
        MM_SHARP equ 183
        MM_LUCENT equ 184
        MM_ATT equ 185
        MM_SUNCOM equ 186
        MM_SORVIS equ 187
        MM_INVISION equ 188
        MM_BERKOM equ 189
        MM_MARIAN equ 190
        MM_DPSINC equ 191
        MM_BCB equ 192
        MM_MOTIONPIXELS equ 193
        MM_QDESIGN equ 194
        MM_NMP equ 195
        MM_DATAFUSION equ 196
        MM_DUCK equ 197
        MM_FTR equ 198
        MM_BERCOS equ 199
        MM_ONLIVE equ 200
        MM_SIEMENS_SBC equ 201
        MM_TERALOGIC equ 202
        MM_PHONET equ 203
        MM_WINBOND equ 204
        MM_VIRTUALMUSIC equ 205
        MM_ENET equ 206
        MM_GUILLEMOT equ 207
        MM_EMAGIC equ 208
        MM_MWM equ 209
        MM_PACIFICRESEARCH equ 210
        MM_SIPROLAB equ 211
        MM_LYNX equ 212
        MM_SPECTRUM_PRODUCTIONS equ 213
        MM_DICTAPHONE equ 214
        MM_QUALCOMM equ 215
        MM_RZS equ 216
        MM_AUDIOSCIENCE equ 217
        MM_PINNACLE equ 218
        MM_EES equ 219
        MM_HAFTMANN equ 220
        MM_LUCID equ 221
        MM_HEADSPACE equ 222
        MM_UNISYS equ 223
        MM_LUMINOSITI equ 224
        MM_ACTIVEVOICE equ 225
        MM_DTS equ 226
        MM_DIGIGRAM equ 227
        MM_SOFTLAB_NSK equ 228
        MM_FORTEMEDIA equ 229
        MM_SONORUS equ 230
        MM_ARRAY equ 231
        MM_DATARAN equ 232
        MM_I_LINK equ 233
        MM_SELSIUS_SYSTEMS equ 234
        MM_ADMOS equ 235
        MM_LEXICON equ 236
        MM_SGI equ 237
        MM_IPI equ 238
        MM_ICE equ 239
        MM_VQST equ 240
        MM_ETEK equ 241
        MM_CS equ 242
        MM_ALESIS equ 243
        MM_INTERNET equ 244
        MM_SONY equ 245
        MM_HYPERACTIVE equ 246
        MM_UHER_INFORMATIC equ 247
        MM_SYDEC_NV equ 248
        MM_FLEXION equ 249
        MM_VIA equ 250
        MM_MICRONAS equ 251
        MM_ANALOGDEVICES equ 252
        MM_HP equ 253
        MM_MATROX_DIV equ 254
        MM_QUICKAUDIO equ 255
        MM_YOUCOM equ 256
        MM_RICHMOND equ 257
        MM_IODD equ 258
        MM_ICCC equ 259
        MM_3COM equ 260
        MM_MALDEN equ 261
        MM_3DFX equ 262
        MM_MINDMAKER equ 263
        MM_TELEKOL equ 264
        MM_ST_MICROELECTRONICS equ 265
        MM_ALGOVISION equ 266
        MM_UNMAPPED equ 0ffffh
        MM_PID_UNMAPPED equ <MM_UNMAPPED>
        ifdef GUID_DEFINED
          if  not Defined(INIT_MMREG_MID)
            INIT_MMREG_MID macro guid, id
              exitm <{ (guid) - Data1 = 0d5a47fa7h + (id) ; (guid) - Data2 = 6d98h ; (guid) - Data3 = 11d1h ; (guid) - Data4 [ 0 ] = 0a2h ; (guid) - Data4 [ 1 ] = 1ah ; (guid) - Data4 [ 2 ] = 00h ; (guid) - Data4 [ 3 ] = 0a0h ; (guid) - Data4 [ 4 ] = 0c9h ; (guid) - Data4 [ 5 ] = 22h ; (guid) - Data4 [ 6 ] = 31h ; (guid) - Data4 [ 7 ] = 96h ; }>
            endm
            EXTRACT_MMREG_MID macro guid
              exitm <((guid) - Data1 - 0d5a47fa7h)>
            endm
            DEFINE_MMREG_MID_GUID macro id
              exitm <0d5a47fa7h + (id), 6d98h, 11d1h, 0a2h, 1ah, 00h, 0a0h, 0c9h, 22h, 31h, 96h>
            endm
            IS_COMPATIBLE_MMREG_MID macro guid
              exitm <(((guid) - Data1 >= 0d5a47fa7h) and ((guid) - Data1 < 0d5a47fa7h + 0ffffh) and ((guid) - Data2 == 6d98h) and ((guid) - Data3 == 11d1h) and ((guid) - Data4 [ 0 ] == 0a2h) and ((guid) - Data4 [ 1 ] == 1ah) and ((guid) - Data4 [ 2 ] == 00h) and ((guid) - Data4 [ 3 ] == 0a0h) and ((guid) - Data4 [ 4 ] == 0c9h) and ((guid) - Data4 [ 5 ] == 22h) and ((guid) - Data4 [ 6 ] == 31h) and ((guid) - Data4 [ 7 ] == 96h))>
            endm
          endif
          if  not Defined(INIT_MMREG_PID)
            INIT_MMREG_PID macro guid, id
              exitm <{ (guid) - Data1 = 0e36dc2ach + (id) ; (guid) - Data2 = 6d9ah ; (guid) - Data3 = 11d1h ; (guid) - Data4 [ 0 ] = 0a2h ; (guid) - Data4 [ 1 ] = 1ah ; (guid) - Data4 [ 2 ] = 00h ; (guid) - Data4 [ 3 ] = 0a0h ; (guid) - Data4 [ 4 ] = 0c9h ; (guid) - Data4 [ 5 ] = 22h ; (guid) - Data4 [ 6 ] = 31h ; (guid) - Data4 [ 7 ] = 96h ; }>
            endm
            EXTRACT_MMREG_PID macro guid
              exitm <((guid) - Data1 - 0e36dc2ach)>
            endm
            DEFINE_MMREG_PID_GUID macro id
              exitm <0e36dc2ach + (id), 6d9ah, 11d1h, 0a2h, 1ah, 00h, 0a0h, 0c9h, 22h, 31h, 96h>
            endm
            IS_COMPATIBLE_MMREG_PID macro guid
              exitm <(((guid) - Data1 >= 0e36dc2ach) and ((guid) - Data1 < 0e36dc2ach + 0ffffh) and ((guid) - Data2 == 6d9ah) and ((guid) - Data3 == 11d1h) and ((guid) - Data4 [ 0 ] == 0a2h) and ((guid) - Data4 [ 1 ] == 1ah) and ((guid) - Data4 [ 2 ] == 00h) and ((guid) - Data4 [ 3 ] == 0a0h) and ((guid) - Data4 [ 4 ] == 0c9h) and ((guid) - Data4 [ 5 ] == 22h) and ((guid) - Data4 [ 6 ] == 31h) and ((guid) - Data4 [ 7 ] == 96h))>
            endm
          endif
        endif
        ifndef MM_MIDI_MAPPER
          MM_MIDI_MAPPER equ 1
          MM_WAVE_MAPPER equ 2
          MM_SNDBLST_MIDIOUT equ 3
          MM_SNDBLST_MIDIIN equ 4
          MM_SNDBLST_SYNTH equ 5
          MM_SNDBLST_WAVEOUT equ 6
          MM_SNDBLST_WAVEIN equ 7
          MM_ADLIB equ 9
          MM_MPU401_MIDIOUT equ 10
          MM_MPU401_MIDIIN equ 11
          MM_PC_JOYSTICK equ 12
        endif
        MM_PCSPEAKER_WAVEOUT equ 13
        MM_MSFT_WSS_WAVEIN equ 14
        MM_MSFT_WSS_WAVEOUT equ 15
        MM_MSFT_WSS_FMSYNTH_STEREO equ 16
        MM_MSFT_WSS_MIXER equ 17
        MM_MSFT_WSS_OEM_WAVEIN equ 18
        MM_MSFT_WSS_OEM_WAVEOUT equ 19
        MM_MSFT_WSS_OEM_FMSYNTH_STEREO equ 20
        MM_MSFT_WSS_AUX equ 21
        MM_MSFT_WSS_OEM_AUX equ 22
        MM_MSFT_GENERIC_WAVEIN equ 23
        MM_MSFT_GENERIC_WAVEOUT equ 24
        MM_MSFT_GENERIC_MIDIIN equ 25
        MM_MSFT_GENERIC_MIDIOUT equ 26
        MM_MSFT_GENERIC_MIDISYNTH equ 27
        MM_MSFT_GENERIC_AUX_LINE equ 28
        MM_MSFT_GENERIC_AUX_MIC equ 29
        MM_MSFT_GENERIC_AUX_CD equ 30
        MM_MSFT_WSS_OEM_MIXER equ 31
        MM_MSFT_MSACM equ 32
        MM_MSFT_ACM_MSADPCM equ 33
        MM_MSFT_ACM_IMAADPCM equ 34
        MM_MSFT_ACM_MSFILTER equ 35
        MM_MSFT_ACM_GSM610 equ 36
        MM_MSFT_ACM_G711 equ 37
        MM_MSFT_ACM_PCM equ 38
        MM_WSS_SB16_WAVEIN equ 39
        MM_WSS_SB16_WAVEOUT equ 40
        MM_WSS_SB16_MIDIIN equ 41
        MM_WSS_SB16_MIDIOUT equ 42
        MM_WSS_SB16_SYNTH equ 43
        MM_WSS_SB16_AUX_LINE equ 44
        MM_WSS_SB16_AUX_CD equ 45
        MM_WSS_SB16_MIXER equ 46
        MM_WSS_SBPRO_WAVEIN equ 47
        MM_WSS_SBPRO_WAVEOUT equ 48
        MM_WSS_SBPRO_MIDIIN equ 49
        MM_WSS_SBPRO_MIDIOUT equ 50
        MM_WSS_SBPRO_SYNTH equ 51
        MM_WSS_SBPRO_AUX_LINE equ 52
        MM_WSS_SBPRO_AUX_CD equ 53
        MM_WSS_SBPRO_MIXER equ 54
        MM_MSFT_WSS_NT_WAVEIN equ 55
        MM_MSFT_WSS_NT_WAVEOUT equ 56
        MM_MSFT_WSS_NT_FMSYNTH_STEREO equ 57
        MM_MSFT_WSS_NT_MIXER equ 58
        MM_MSFT_WSS_NT_AUX equ 59
        MM_MSFT_SB16_WAVEIN equ 60
        MM_MSFT_SB16_WAVEOUT equ 61
        MM_MSFT_SB16_MIDIIN equ 62
        MM_MSFT_SB16_MIDIOUT equ 63
        MM_MSFT_SB16_SYNTH equ 64
        MM_MSFT_SB16_AUX_LINE equ 65
        MM_MSFT_SB16_AUX_CD equ 66
        MM_MSFT_SB16_MIXER equ 67
        MM_MSFT_SBPRO_WAVEIN equ 68
        MM_MSFT_SBPRO_WAVEOUT equ 69
        MM_MSFT_SBPRO_MIDIIN equ 70
        MM_MSFT_SBPRO_MIDIOUT equ 71
        MM_MSFT_SBPRO_SYNTH equ 72
        MM_MSFT_SBPRO_AUX_LINE equ 73
        MM_MSFT_SBPRO_AUX_CD equ 74
        MM_MSFT_SBPRO_MIXER equ 75
        MM_MSFT_MSOPL_SYNTH equ 76
        MM_MSFT_VMDMS_LINE_WAVEIN equ 80
        MM_MSFT_VMDMS_LINE_WAVEOUT equ 81
        MM_MSFT_VMDMS_HANDSET_WAVEIN equ 82
        MM_MSFT_VMDMS_HANDSET_WAVEOUT equ 83
        MM_MSFT_VMDMW_LINE_WAVEIN equ 84
        MM_MSFT_VMDMW_LINE_WAVEOUT equ 85
        MM_MSFT_VMDMW_HANDSET_WAVEIN equ 86
        MM_MSFT_VMDMW_HANDSET_WAVEOUT equ 87
        MM_MSFT_VMDMW_MIXER equ 88
        MM_MSFT_VMDM_GAME_WAVEOUT equ 89
        MM_MSFT_VMDM_GAME_WAVEIN equ 90
        MM_MSFT_ACM_MSNAUDIO equ 91
        MM_MSFT_ACM_MSG723 equ 92
        MM_MSFT_ACM_MSRT24 equ 93
        MM_MSFT_WDMAUDIO_WAVEOUT equ 100
        MM_MSFT_WDMAUDIO_WAVEIN equ 101
        MM_MSFT_WDMAUDIO_MIDIOUT equ 102
        MM_MSFT_WDMAUDIO_MIDIIN equ 103
        MM_MSFT_WDMAUDIO_MIXER equ 104
        MM_MSFT_WDMAUDIO_AUX equ 105
        MM_CREATIVE_SB15_WAVEIN equ 1
        MM_CREATIVE_SB20_WAVEIN equ 2
        MM_CREATIVE_SBPRO_WAVEIN equ 3
        MM_CREATIVE_SBP16_WAVEIN equ 4
        MM_CREATIVE_PHNBLST_WAVEIN equ 5
        MM_CREATIVE_SB15_WAVEOUT equ 101
        MM_CREATIVE_SB20_WAVEOUT equ 102
        MM_CREATIVE_SBPRO_WAVEOUT equ 103
        MM_CREATIVE_SBP16_WAVEOUT equ 104
        MM_CREATIVE_PHNBLST_WAVEOUT equ 105
        MM_CREATIVE_MIDIOUT equ 201
        MM_CREATIVE_MIDIIN equ 202
        MM_CREATIVE_FMSYNTH_MONO equ 301
        MM_CREATIVE_FMSYNTH_STEREO equ 302
        MM_CREATIVE_MIDI_AWE32 equ 303
        MM_CREATIVE_AUX_CD equ 401
        MM_CREATIVE_AUX_LINE equ 402
        MM_CREATIVE_AUX_MIC equ 403
        MM_CREATIVE_AUX_MASTER equ 404
        MM_CREATIVE_AUX_PCSPK equ 405
        MM_CREATIVE_AUX_WAVE equ 406
        MM_CREATIVE_AUX_MIDI equ 407
        MM_CREATIVE_SBPRO_MIXER equ 408
        MM_CREATIVE_SB16_MIXER equ 409
        MM_MEDIAVISION_PROAUDIO equ 10h
        MM_PROAUD_MIDIOUT equ (MM_MEDIAVISION_PROAUDIO + 1)
        MM_PROAUD_MIDIIN equ (MM_MEDIAVISION_PROAUDIO + 2)
        MM_PROAUD_SYNTH equ (MM_MEDIAVISION_PROAUDIO + 3)
        MM_PROAUD_WAVEOUT equ (MM_MEDIAVISION_PROAUDIO + 4)
        MM_PROAUD_WAVEIN equ (MM_MEDIAVISION_PROAUDIO + 5)
        MM_PROAUD_MIXER equ (MM_MEDIAVISION_PROAUDIO + 6)
        MM_PROAUD_AUX equ (MM_MEDIAVISION_PROAUDIO + 7)
        MM_MEDIAVISION_THUNDER equ 20h
        MM_THUNDER_SYNTH equ (MM_MEDIAVISION_THUNDER + 3)
        MM_THUNDER_WAVEOUT equ (MM_MEDIAVISION_THUNDER + 4)
        MM_THUNDER_WAVEIN equ (MM_MEDIAVISION_THUNDER + 5)
        MM_THUNDER_AUX equ (MM_MEDIAVISION_THUNDER + 7)
        MM_MEDIAVISION_TPORT equ 40h
        MM_TPORT_WAVEOUT equ (MM_MEDIAVISION_TPORT + 1)
        MM_TPORT_WAVEIN equ (MM_MEDIAVISION_TPORT + 2)
        MM_TPORT_SYNTH equ (MM_MEDIAVISION_TPORT + 3)
        MM_MEDIAVISION_PROAUDIO_PLUS equ 50h
        MM_PROAUD_PLUS_MIDIOUT equ (MM_MEDIAVISION_PROAUDIO_PLUS + 1)
        MM_PROAUD_PLUS_MIDIIN equ (MM_MEDIAVISION_PROAUDIO_PLUS + 2)
        MM_PROAUD_PLUS_SYNTH equ (MM_MEDIAVISION_PROAUDIO_PLUS + 3)
        MM_PROAUD_PLUS_WAVEOUT equ (MM_MEDIAVISION_PROAUDIO_PLUS + 4)
        MM_PROAUD_PLUS_WAVEIN equ (MM_MEDIAVISION_PROAUDIO_PLUS + 5)
        MM_PROAUD_PLUS_MIXER equ (MM_MEDIAVISION_PROAUDIO_PLUS + 6)
        MM_PROAUD_PLUS_AUX equ (MM_MEDIAVISION_PROAUDIO_PLUS + 7)
        MM_MEDIAVISION_PROAUDIO_16 equ 60h
        MM_PROAUD_16_MIDIOUT equ (MM_MEDIAVISION_PROAUDIO_16 + 1)
        MM_PROAUD_16_MIDIIN equ (MM_MEDIAVISION_PROAUDIO_16 + 2)
        MM_PROAUD_16_SYNTH equ (MM_MEDIAVISION_PROAUDIO_16 + 3)
        MM_PROAUD_16_WAVEOUT equ (MM_MEDIAVISION_PROAUDIO_16 + 4)
        MM_PROAUD_16_WAVEIN equ (MM_MEDIAVISION_PROAUDIO_16 + 5)
        MM_PROAUD_16_MIXER equ (MM_MEDIAVISION_PROAUDIO_16 + 6)
        MM_PROAUD_16_AUX equ (MM_MEDIAVISION_PROAUDIO_16 + 7)
        MM_MEDIAVISION_PROSTUDIO_16 equ 60h
        MM_STUDIO_16_MIDIOUT equ (MM_MEDIAVISION_PROSTUDIO_16 + 1)
        MM_STUDIO_16_MIDIIN equ (MM_MEDIAVISION_PROSTUDIO_16 + 2)
        MM_STUDIO_16_SYNTH equ (MM_MEDIAVISION_PROSTUDIO_16 + 3)
        MM_STUDIO_16_WAVEOUT equ (MM_MEDIAVISION_PROSTUDIO_16 + 4)
        MM_STUDIO_16_WAVEIN equ (MM_MEDIAVISION_PROSTUDIO_16 + 5)
        MM_STUDIO_16_MIXER equ (MM_MEDIAVISION_PROSTUDIO_16 + 6)
        MM_STUDIO_16_AUX equ (MM_MEDIAVISION_PROSTUDIO_16 + 7)
        MM_MEDIAVISION_CDPC equ 70h
        MM_CDPC_MIDIOUT equ (MM_MEDIAVISION_CDPC + 1)
        MM_CDPC_MIDIIN equ (MM_MEDIAVISION_CDPC + 2)
        MM_CDPC_SYNTH equ (MM_MEDIAVISION_CDPC + 3)
        MM_CDPC_WAVEOUT equ (MM_MEDIAVISION_CDPC + 4)
        MM_CDPC_WAVEIN equ (MM_MEDIAVISION_CDPC + 5)
        MM_CDPC_MIXER equ (MM_MEDIAVISION_CDPC + 6)
        MM_CDPC_AUX equ (MM_MEDIAVISION_CDPC + 7)
        MM_MEDIAVISION_OPUS1208 equ 80h
        MM_OPUS401_MIDIOUT equ (MM_MEDIAVISION_OPUS1208 + 1)
        MM_OPUS401_MIDIIN equ (MM_MEDIAVISION_OPUS1208 + 2)
        MM_OPUS1208_SYNTH equ (MM_MEDIAVISION_OPUS1208 + 3)
        MM_OPUS1208_WAVEOUT equ (MM_MEDIAVISION_OPUS1208 + 4)
        MM_OPUS1208_WAVEIN equ (MM_MEDIAVISION_OPUS1208 + 5)
        MM_OPUS1208_MIXER equ (MM_MEDIAVISION_OPUS1208 + 6)
        MM_OPUS1208_AUX equ (MM_MEDIAVISION_OPUS1208 + 7)
        MM_MEDIAVISION_OPUS1216 equ 90h
        MM_OPUS1216_MIDIOUT equ (MM_MEDIAVISION_OPUS1216 + 1)
        MM_OPUS1216_MIDIIN equ (MM_MEDIAVISION_OPUS1216 + 2)
        MM_OPUS1216_SYNTH equ (MM_MEDIAVISION_OPUS1216 + 3)
        MM_OPUS1216_WAVEOUT equ (MM_MEDIAVISION_OPUS1216 + 4)
        MM_OPUS1216_WAVEIN equ (MM_MEDIAVISION_OPUS1216 + 5)
        MM_OPUS1216_MIXER equ (MM_MEDIAVISION_OPUS1216 + 6)
        MM_OPUS1216_AUX equ (MM_MEDIAVISION_OPUS1216 + 7)
        MM_CYRIX_XASYNTH equ 1
        MM_CYRIX_XAMIDIIN equ 2
        MM_CYRIX_XAMIDIOUT equ 3
        MM_CYRIX_XAWAVEIN equ 4
        MM_CYRIX_XAWAVEOUT equ 5
        MM_CYRIX_XAAUX equ 6
        MM_CYRIX_XAMIXER equ 7
        MM_PHILIPS_ACM_LPCBB equ 1
        MM_NETXL_XLVIDEO equ 1
        MM_ZYXEL_ACM_ADPCM equ 1
        MM_AARDVARK_STUDIO12_WAVEOUT equ 1
        MM_AARDVARK_STUDIO12_WAVEIN equ 2
        MM_AARDVARK_STUDIO88_WAVEOUT equ 3
        MM_AARDVARK_STUDIO88_WAVEIN equ 4
        MM_BINTEC_TAPI_WAVE equ 1
        MM_HEWLETT_PACKARD_CU_CODEC equ 1
        MM_MITEL_TALKTO_LINE_WAVEOUT equ 100
        MM_MITEL_TALKTO_LINE_WAVEIN equ 101
        MM_MITEL_TALKTO_HANDSET_WAVEOUT equ 102
        MM_MITEL_TALKTO_HANDSET_WAVEIN equ 103
        MM_MITEL_TALKTO_BRIDGED_WAVEOUT equ 104
        MM_MITEL_TALKTO_BRIDGED_WAVEIN equ 105
        MM_MITEL_MPA_HANDSET_WAVEOUT equ 200
        MM_MITEL_MPA_HANDSET_WAVEIN equ 201
        MM_MITEL_MPA_HANDSFREE_WAVEOUT equ 202
        MM_MITEL_MPA_HANDSFREE_WAVEIN equ 203
        MM_MITEL_MPA_LINE1_WAVEOUT equ 204
        MM_MITEL_MPA_LINE1_WAVEIN equ 205
        MM_MITEL_MPA_LINE2_WAVEOUT equ 206
        MM_MITEL_MPA_LINE2_WAVEIN equ 207
        MM_MITEL_MEDIAPATH_WAVEOUT equ 300
        MM_MITEL_MEDIAPATH_WAVEIN equ 301
        MM_SNI_ACM_G721 equ 1
        MM_EMU_APSSYNTH equ 1
        MM_EMU_APSMIDIIN equ 2
        MM_EMU_APSMIDIOUT equ 3
        MM_EMU_APSWAVEIN equ 4
        MM_EMU_APSWAVEOUT equ 5
        MM_ARTISOFT_SBWAVEIN equ 1
        MM_ARTISOFT_SBWAVEOUT equ 2
        MM_TBS_TROPEZ_WAVEIN equ 37
        MM_TBS_TROPEZ_WAVEOUT equ 38
        MM_TBS_TROPEZ_AUX1 equ 39
        MM_TBS_TROPEZ_AUX2 equ 40
        MM_TBS_TROPEZ_LINE equ 41
        MM_MMOTION_WAVEAUX equ 1
        MM_MMOTION_WAVEOUT equ 2
        MM_MMOTION_WAVEIN equ 3
        MM_IBM_PCMCIA_WAVEIN equ 11
        MM_IBM_PCMCIA_WAVEOUT equ 12
        MM_IBM_PCMCIA_SYNTH equ 13
        MM_IBM_PCMCIA_MIDIIN equ 14
        MM_IBM_PCMCIA_MIDIOUT equ 15
        MM_IBM_PCMCIA_AUX equ 16
        MM_IBM_THINKPAD200 equ 17
        MM_IBM_MWAVE_WAVEIN equ 18
        MM_IBM_MWAVE_WAVEOUT equ 19
        MM_IBM_MWAVE_MIXER equ 20
        MM_IBM_MWAVE_MIDIIN equ 21
        MM_IBM_MWAVE_MIDIOUT equ 22
        MM_IBM_MWAVE_AUX equ 23
        MM_IBM_WC_MIDIOUT equ 30
        MM_IBM_WC_WAVEOUT equ 31
        MM_IBM_WC_MIXEROUT equ 33
        MM_VOCALTEC_WAVEOUT equ 1
        MM_VOCALTEC_WAVEIN equ 2
        MM_ROLAND_RAP10_MIDIOUT equ 10
        MM_ROLAND_RAP10_MIDIIN equ 11
        MM_ROLAND_RAP10_SYNTH equ 12
        MM_ROLAND_RAP10_WAVEOUT equ 13
        MM_ROLAND_RAP10_WAVEIN equ 14
        MM_ROLAND_MPU401_MIDIOUT equ 15
        MM_ROLAND_MPU401_MIDIIN equ 16
        MM_ROLAND_SMPU_MIDIOUTA equ 17
        MM_ROLAND_SMPU_MIDIOUTB equ 18
        MM_ROLAND_SMPU_MIDIINA equ 19
        MM_ROLAND_SMPU_MIDIINB equ 20
        MM_ROLAND_SC7_MIDIOUT equ 21
        MM_ROLAND_SC7_MIDIIN equ 22
        MM_ROLAND_SERIAL_MIDIOUT equ 23
        MM_ROLAND_SERIAL_MIDIIN equ 24
        MM_ROLAND_SCP_MIDIOUT equ 38
        MM_ROLAND_SCP_MIDIIN equ 39
        MM_ROLAND_SCP_WAVEOUT equ 40
        MM_ROLAND_SCP_WAVEIN equ 41
        MM_ROLAND_SCP_MIXER equ 42
        MM_ROLAND_SCP_AUX equ 48
        MM_DSP_SOLUTIONS_WAVEOUT equ 1
        MM_DSP_SOLUTIONS_WAVEIN equ 2
        MM_DSP_SOLUTIONS_SYNTH equ 3
        MM_DSP_SOLUTIONS_AUX equ 4
        MM_NEC_73_86_SYNTH equ 5
        MM_NEC_73_86_WAVEOUT equ 6
        MM_NEC_73_86_WAVEIN equ 7
        MM_NEC_26_SYNTH equ 9
        MM_NEC_MPU401_MIDIOUT equ 10
        MM_NEC_MPU401_MIDIIN equ 11
        MM_NEC_JOYSTICK equ 12
        MM_WANGLABS_WAVEIN1 equ 1
        MM_WANGLABS_WAVEOUT1 equ 2
        MM_TANDY_VISWAVEIN equ 1
        MM_TANDY_VISWAVEOUT equ 2
        MM_TANDY_VISBIOSSYNTH equ 3
        MM_TANDY_SENS_MMAWAVEIN equ 4
        MM_TANDY_SENS_MMAWAVEOUT equ 5
        MM_TANDY_SENS_MMAMIDIIN equ 6
        MM_TANDY_SENS_MMAMIDIOUT equ 7
        MM_TANDY_SENS_VISWAVEOUT equ 8
        MM_TANDY_PSSJWAVEIN equ 9
        MM_TANDY_PSSJWAVEOUT equ 10
        MM_ANTEX_SX12_WAVEIN equ 1
        MM_ANTEX_SX12_WAVEOUT equ 2
        MM_ANTEX_SX15_WAVEIN equ 3
        MM_ANTEX_SX15_WAVEOUT equ 4
        MM_ANTEX_VP625_WAVEIN equ 5
        MM_ANTEX_VP625_WAVEOUT equ 6
        MM_ANTEX_AUDIOPORT22_WAVEIN equ 7
        MM_ANTEX_AUDIOPORT22_WAVEOUT equ 8
        MM_ANTEX_AUDIOPORT22_FEEDTHRU equ 9
        MM_INTELOPD_WAVEIN equ 1
        MM_INTELOPD_WAVEOUT equ 101
        MM_INTELOPD_AUX equ 401
        MM_INTEL_NSPMODEMLINEIN equ 501
        MM_INTEL_NSPMODEMLINEOUT equ 502
        MM_VAL_MICROKEY_AP_WAVEIN equ 1
        MM_VAL_MICROKEY_AP_WAVEOUT equ 2
        MM_INTERACTIVE_WAVEIN equ 45h
        MM_INTERACTIVE_WAVEOUT equ 45h
        MM_YAMAHA_GSS_SYNTH equ 01h
        MM_YAMAHA_GSS_WAVEOUT equ 02h
        MM_YAMAHA_GSS_WAVEIN equ 03h
        MM_YAMAHA_GSS_MIDIOUT equ 04h
        MM_YAMAHA_GSS_MIDIIN equ 05h
        MM_YAMAHA_GSS_AUX equ 06h
        MM_YAMAHA_SERIAL_MIDIOUT equ 07h
        MM_YAMAHA_SERIAL_MIDIIN equ 08h
        MM_YAMAHA_OPL3SA_WAVEOUT equ 10h
        MM_YAMAHA_OPL3SA_WAVEIN equ 11h
        MM_YAMAHA_OPL3SA_FMSYNTH equ 12h
        MM_YAMAHA_OPL3SA_YSYNTH equ 13h
        MM_YAMAHA_OPL3SA_MIDIOUT equ 14h
        MM_YAMAHA_OPL3SA_MIDIIN equ 15h
        MM_YAMAHA_OPL3SA_MIXER equ 17h
        MM_YAMAHA_OPL3SA_JOYSTICK equ 18h
        MM_YAMAHA_YMF724LEG_MIDIOUT equ 19h
        MM_YAMAHA_YMF724LEG_MIDIIN equ 1ah
        MM_YAMAHA_YMF724_WAVEOUT equ 1bh
        MM_YAMAHA_YMF724_WAVEIN equ 1ch
        MM_YAMAHA_YMF724_MIDIOUT equ 1dh
        MM_YAMAHA_YMF724_AUX equ 1eh
        MM_YAMAHA_YMF724_MIXER equ 1fh
        MM_YAMAHA_YMF724LEG_FMSYNTH equ 20h
        MM_YAMAHA_YMF724LEG_MIXER equ 21h
        MM_YAMAHA_SXG_MIDIOUT equ 22h
        MM_YAMAHA_SXG_WAVEOUT equ 23h
        MM_YAMAHA_SXG_MIXER equ 24h
        MM_YAMAHA_ACXG_WAVEIN equ 25h
        MM_YAMAHA_ACXG_WAVEOUT equ 26h
        MM_YAMAHA_ACXG_MIDIOUT equ 27h
        MM_YAMAHA_ACXG_MIXER equ 28h
        MM_YAMAHA_ACXG_AUX equ 29h
        MM_EVEREX_CARRIER equ 1
        MM_ECHO_SYNTH equ 1
        MM_ECHO_WAVEOUT equ 2
        MM_ECHO_WAVEIN equ 3
        MM_ECHO_MIDIOUT equ 4
        MM_ECHO_MIDIIN equ 5
        MM_ECHO_AUX equ 6
        MM_SIERRA_ARIA_MIDIOUT equ 14h
        MM_SIERRA_ARIA_MIDIIN equ 15h
        MM_SIERRA_ARIA_SYNTH equ 16h
        MM_SIERRA_ARIA_WAVEOUT equ 17h
        MM_SIERRA_ARIA_WAVEIN equ 18h
        MM_SIERRA_ARIA_AUX equ 19h
        MM_SIERRA_ARIA_AUX2 equ 20h
        MM_SIERRA_QUARTET_WAVEIN equ 50h
        MM_SIERRA_QUARTET_WAVEOUT equ 51h
        MM_SIERRA_QUARTET_MIDIIN equ 52h
        MM_SIERRA_QUARTET_MIDIOUT equ 53h
        MM_SIERRA_QUARTET_SYNTH equ 54h
        MM_SIERRA_QUARTET_AUX_CD equ 55h
        MM_SIERRA_QUARTET_AUX_LINE equ 56h
        MM_SIERRA_QUARTET_AUX_MODEM equ 57h
        MM_SIERRA_QUARTET_MIXER equ 58h
        MM_CAT_WAVEOUT equ 1
        MM_DSP_GROUP_TRUESPEECH equ 1
        MM_MELABS_MIDI2GO equ 1
        MM_ESS_AMWAVEOUT equ 01h
        MM_ESS_AMWAVEIN equ 02h
        MM_ESS_AMAUX equ 03h
        MM_ESS_AMSYNTH equ 04h
        MM_ESS_AMMIDIOUT equ 05h
        MM_ESS_AMMIDIIN equ 06h
        MM_ESS_MIXER equ 07h
        MM_ESS_AUX_CD equ 08h
        MM_ESS_MPU401_MIDIOUT equ 09h
        MM_ESS_MPU401_MIDIIN equ 0Ah
        MM_ESS_ES488_WAVEOUT equ 10h
        MM_ESS_ES488_WAVEIN equ 11h
        MM_ESS_ES488_MIXER equ 12h
        MM_ESS_ES688_WAVEOUT equ 13h
        MM_ESS_ES688_WAVEIN equ 14h
        MM_ESS_ES688_MIXER equ 15h
        MM_ESS_ES1488_WAVEOUT equ 16h
        MM_ESS_ES1488_WAVEIN equ 17h
        MM_ESS_ES1488_MIXER equ 18h
        MM_ESS_ES1688_WAVEOUT equ 19h
        MM_ESS_ES1688_WAVEIN equ 1Ah
        MM_ESS_ES1688_MIXER equ 1Bh
        MM_ESS_ES1788_WAVEOUT equ 1Ch
        MM_ESS_ES1788_WAVEIN equ 1Dh
        MM_ESS_ES1788_MIXER equ 1Eh
        MM_ESS_ES1888_WAVEOUT equ 1Fh
        MM_ESS_ES1888_WAVEIN equ 20h
        MM_ESS_ES1888_MIXER equ 21h
        MM_ESS_ES1868_WAVEOUT equ 22h
        MM_ESS_ES1868_WAVEIN equ 23h
        MM_ESS_ES1868_MIXER equ 24h
        MM_ESS_ES1878_WAVEOUT equ 25h
        MM_ESS_ES1878_WAVEIN equ 26h
        MM_ESS_ES1878_MIXER equ 27h
        MM_CANOPUS_ACM_DVREX equ 1
        MM_EPS_FMSND equ 1
        MM_TRUEVISION_WAVEIN1 equ 1
        MM_TRUEVISION_WAVEOUT1 equ 2
        MM_AZTECH_MIDIOUT equ 3
        MM_AZTECH_MIDIIN equ 4
        MM_AZTECH_WAVEIN equ 17
        MM_AZTECH_WAVEOUT equ 18
        MM_AZTECH_FMSYNTH equ 20
        MM_AZTECH_MIXER equ 21
        MM_AZTECH_PRO16_WAVEIN equ 33
        MM_AZTECH_PRO16_WAVEOUT equ 34
        MM_AZTECH_PRO16_FMSYNTH equ 38
        MM_AZTECH_DSP16_WAVEIN equ 65
        MM_AZTECH_DSP16_WAVEOUT equ 66
        MM_AZTECH_DSP16_FMSYNTH equ 68
        MM_AZTECH_DSP16_WAVESYNTH equ 70
        MM_AZTECH_NOVA16_WAVEIN equ 71
        MM_AZTECH_NOVA16_WAVEOUT equ 72
        MM_AZTECH_NOVA16_MIXER equ 73
        MM_AZTECH_WASH16_WAVEIN equ 74
        MM_AZTECH_WASH16_WAVEOUT equ 75
        MM_AZTECH_WASH16_MIXER equ 76
        MM_AZTECH_AUX_CD equ 401
        MM_AZTECH_AUX_LINE equ 402
        MM_AZTECH_AUX_MIC equ 403
        MM_AZTECH_AUX equ 404
        MM_VIDEOLOGIC_MSWAVEIN equ 1
        MM_VIDEOLOGIC_MSWAVEOUT equ 2
        MM_KORG_PCIF_MIDIOUT equ 1
        MM_KORG_PCIF_MIDIIN equ 2
        MM_KORG_1212IO_MSWAVEIN equ 3
        MM_KORG_1212IO_MSWAVEOUT equ 4
        MM_APT_ACE100CD equ 1
        MM_ICS_WAVEDECK_WAVEOUT equ 1
        MM_ICS_WAVEDECK_WAVEIN equ 2
        MM_ICS_WAVEDECK_MIXER equ 3
        MM_ICS_WAVEDECK_AUX equ 4
        MM_ICS_WAVEDECK_SYNTH equ 5
        MM_ICS_WAVEDEC_SB_WAVEOUT equ 6
        MM_ICS_WAVEDEC_SB_WAVEIN equ 7
        MM_ICS_WAVEDEC_SB_FM_MIDIOUT equ 8
        MM_ICS_WAVEDEC_SB_MPU401_MIDIOUT equ 9
        MM_ICS_WAVEDEC_SB_MPU401_MIDIIN equ 10
        MM_ICS_WAVEDEC_SB_MIXER equ 11
        MM_ICS_WAVEDEC_SB_AUX equ 12
        MM_ICS_2115_LITE_MIDIOUT equ 13
        MM_ICS_2120_LITE_MIDIOUT equ 14
        MM_ITERATEDSYS_FUFCODEC equ 1
        MM_METHEUS_ZIPPER equ 1
        MM_WINNOV_CAVIAR_WAVEIN equ 1
        MM_WINNOV_CAVIAR_WAVEOUT equ 2
        MM_WINNOV_CAVIAR_VIDC equ 3
        MM_WINNOV_CAVIAR_CHAMPAGNE equ 4
        MM_WINNOV_CAVIAR_YUV8 equ 5
        MM_NCR_BA_WAVEIN equ 1
        MM_NCR_BA_WAVEOUT equ 2
        MM_NCR_BA_SYNTH equ 3
        MM_NCR_BA_AUX equ 4
        MM_NCR_BA_MIXER equ 5
        MM_AST_MODEMWAVE_WAVEIN equ 13
        MM_AST_MODEMWAVE_WAVEOUT equ 14
        MM_WILLOWPOND_FMSYNTH_STEREO equ 20
        MM_WILLOWPOND_MPU401 equ 21
        MM_WILLOWPOND_SNDPORT_WAVEIN equ 100
        MM_WILLOWPOND_SNDPORT_WAVEOUT equ 101
        MM_WILLOWPOND_SNDPORT_MIXER equ 102
        MM_WILLOWPOND_SNDPORT_AUX equ 103
        MM_WILLOWPOND_PH_WAVEIN equ 104
        MM_WILLOWPOND_PH_WAVEOUT equ 105
        MM_WILLOWPOND_PH_MIXER equ 106
        MM_WILLOWPOND_PH_AUX equ 107
        MM_WILLOPOND_SNDCOMM_WAVEIN equ 108
        MM_WILLOWPOND_SNDCOMM_WAVEOUT equ 109
        MM_WILLOWPOND_SNDCOMM_MIXER equ 110
        MM_WILLOWPOND_SNDCOMM_AUX equ 111
        MM_WILLOWPOND_GENERIC_WAVEIN equ 112
        MM_WILLOWPOND_GENERIC_WAVEOUT equ 113
        MM_WILLOWPOND_GENERIC_MIXER equ 114
        MM_WILLOWPOND_GENERIC_AUX equ 115
        MM_VITEC_VMAKER equ 1
        MM_VITEC_VMPRO equ 2
        MM_MOSCOM_VPC2400_IN equ 1
        MM_MOSCOM_VPC2400_OUT equ 2
        MM_SILICONSOFT_SC1_WAVEIN equ 1
        MM_SILICONSOFT_SC1_WAVEOUT equ 2
        MM_SILICONSOFT_SC2_WAVEIN equ 3
        MM_SILICONSOFT_SC2_WAVEOUT equ 4
        MM_SILICONSOFT_SOUNDJR2_WAVEOUT equ 5
        MM_SILICONSOFT_SOUNDJR2PR_WAVEIN equ 6
        MM_SILICONSOFT_SOUNDJR2PR_WAVEOUT equ 7
        MM_SILICONSOFT_SOUNDJR3_WAVEOUT equ 8
        MM_TTEWS_WAVEIN equ 1
        MM_TTEWS_WAVEOUT equ 2
        MM_TTEWS_MIDIIN equ 3
        MM_TTEWS_MIDIOUT equ 4
        MM_TTEWS_MIDISYNTH equ 5
        MM_TTEWS_MIDIMONITOR equ 6
        MM_TTEWS_VMIDIIN equ 7
        MM_TTEWS_VMIDIOUT equ 8
        MM_TTEWS_AUX equ 9
        MM_TTEWS_MIXER equ 10
        MM_MEDIASONIC_ACM_G723 equ 1
        MM_MEDIASONIC_ICOM equ 2
        MM_ICOM_WAVEIN equ 3
        MM_ICOM_WAVEOUT equ 4
        MM_ICOM_MIXER equ 5
        MM_ICOM_AUX equ 6
        MM_ICOM_LINE equ 7
        MM_SANYO_ACM_LD_ADPCM equ 1
        MM_AHEAD_MULTISOUND equ 1
        MM_AHEAD_SOUNDBLASTER equ 2
        MM_AHEAD_PROAUDIO equ 3
        MM_AHEAD_GENERIC equ 4
        MM_OLIVETTI_WAVEIN equ 1
        MM_OLIVETTI_WAVEOUT equ 2
        MM_OLIVETTI_MIXER equ 3
        MM_OLIVETTI_AUX equ 4
        MM_OLIVETTI_MIDIIN equ 5
        MM_OLIVETTI_MIDIOUT equ 6
        MM_OLIVETTI_SYNTH equ 7
        MM_OLIVETTI_JOYSTICK equ 8
        MM_OLIVETTI_ACM_GSM equ 9
        MM_OLIVETTI_ACM_ADPCM equ 10
        MM_OLIVETTI_ACM_CELP equ 11
        MM_OLIVETTI_ACM_SBC equ 12
        MM_OLIVETTI_ACM_OPR equ 13
        MM_IOMAGIC_TEMPO_WAVEOUT equ 1
        MM_IOMAGIC_TEMPO_WAVEIN equ 2
        MM_IOMAGIC_TEMPO_SYNTH equ 3
        MM_IOMAGIC_TEMPO_MIDIOUT equ 4
        MM_IOMAGIC_TEMPO_MXDOUT equ 5
        MM_IOMAGIC_TEMPO_AUXOUT equ 6
        MM_MATSUSHITA_WAVEIN equ 1
        MM_MATSUSHITA_WAVEOUT equ 2
        MM_MATSUSHITA_FMSYNTH_STEREO equ 3
        MM_MATSUSHITA_MIXER equ 4
        MM_MATSUSHITA_AUX equ 5
        MM_NEWMEDIA_WAVJAMMER equ 1
        MM_LYRRUS_BRIDGE_GUITAR equ 1
        MM_OPTI_M16_FMSYNTH_STEREO equ 0001h
        MM_OPTI_M16_MIDIIN equ 0002h
        MM_OPTI_M16_MIDIOUT equ 0003h
        MM_OPTI_M16_WAVEIN equ 0004h
        MM_OPTI_M16_WAVEOUT equ 0005h
        MM_OPTI_M16_MIXER equ 0006h
        MM_OPTI_M16_AUX equ 0007h
        MM_OPTI_P16_FMSYNTH_STEREO equ 0010h
        MM_OPTI_P16_MIDIIN equ 0011h
        MM_OPTI_P16_MIDIOUT equ 0012h
        MM_OPTI_P16_WAVEIN equ 0013h
        MM_OPTI_P16_WAVEOUT equ 0014h
        MM_OPTI_P16_MIXER equ 0015h
        MM_OPTI_P16_AUX equ 0016h
        MM_OPTI_M32_WAVEIN equ 0020h
        MM_OPTI_M32_WAVEOUT equ 0021h
        MM_OPTI_M32_MIDIIN equ 0022h
        MM_OPTI_M32_MIDIOUT equ 0023h
        MM_OPTI_M32_SYNTH_STEREO equ 0024h
        MM_OPTI_M32_MIXER equ 0025h
        MM_OPTI_M32_AUX equ 0026h
        MM_COMPAQ_BB_WAVEIN equ 1
        MM_COMPAQ_BB_WAVEOUT equ 2
        MM_COMPAQ_BB_WAVEAUX equ 3
        MM_MPTUS_SPWAVEOUT equ 1
        MM_LERNOUT_ANDHAUSPIE_LHCODECACM equ 1
        MM_DIGITAL_AV320_WAVEIN equ 1
        MM_DIGITAL_AV320_WAVEOUT equ 2
        MM_DIGITAL_ACM_G723 equ 3
        MM_DIGITAL_ICM_H263 equ 4
        MM_DIGITAL_ICM_H261 equ 5
        MM_MOTU_MTP_MIDIOUT_ALL equ 100
        MM_MOTU_MTP_MIDIIN_1 equ 101
        MM_MOTU_MTP_MIDIOUT_1 equ 101
        MM_MOTU_MTP_MIDIIN_2 equ 102
        MM_MOTU_MTP_MIDIOUT_2 equ 102
        MM_MOTU_MTP_MIDIIN_3 equ 103
        MM_MOTU_MTP_MIDIOUT_3 equ 103
        MM_MOTU_MTP_MIDIIN_4 equ 104
        MM_MOTU_MTP_MIDIOUT_4 equ 104
        MM_MOTU_MTP_MIDIIN_5 equ 105
        MM_MOTU_MTP_MIDIOUT_5 equ 105
        MM_MOTU_MTP_MIDIIN_6 equ 106
        MM_MOTU_MTP_MIDIOUT_6 equ 106
        MM_MOTU_MTP_MIDIIN_7 equ 107
        MM_MOTU_MTP_MIDIOUT_7 equ 107
        MM_MOTU_MTP_MIDIIN_8 equ 108
        MM_MOTU_MTP_MIDIOUT_8 equ 108
        MM_MOTU_MTPII_MIDIOUT_ALL equ 200
        MM_MOTU_MTPII_MIDIIN_SYNC equ 200
        MM_MOTU_MTPII_MIDIIN_1 equ 201
        MM_MOTU_MTPII_MIDIOUT_1 equ 201
        MM_MOTU_MTPII_MIDIIN_2 equ 202
        MM_MOTU_MTPII_MIDIOUT_2 equ 202
        MM_MOTU_MTPII_MIDIIN_3 equ 203
        MM_MOTU_MTPII_MIDIOUT_3 equ 203
        MM_MOTU_MTPII_MIDIIN_4 equ 204
        MM_MOTU_MTPII_MIDIOUT_4 equ 204
        MM_MOTU_MTPII_MIDIIN_5 equ 205
        MM_MOTU_MTPII_MIDIOUT_5 equ 205
        MM_MOTU_MTPII_MIDIIN_6 equ 206
        MM_MOTU_MTPII_MIDIOUT_6 equ 206
        MM_MOTU_MTPII_MIDIIN_7 equ 207
        MM_MOTU_MTPII_MIDIOUT_7 equ 207
        MM_MOTU_MTPII_MIDIIN_8 equ 208
        MM_MOTU_MTPII_MIDIOUT_8 equ 208
        MM_MOTU_MTPII_NET_MIDIIN_1 equ 209
        MM_MOTU_MTPII_NET_MIDIOUT_1 equ 209
        MM_MOTU_MTPII_NET_MIDIIN_2 equ 210
        MM_MOTU_MTPII_NET_MIDIOUT_2 equ 210
        MM_MOTU_MTPII_NET_MIDIIN_3 equ 211
        MM_MOTU_MTPII_NET_MIDIOUT_3 equ 211
        MM_MOTU_MTPII_NET_MIDIIN_4 equ 212
        MM_MOTU_MTPII_NET_MIDIOUT_4 equ 212
        MM_MOTU_MTPII_NET_MIDIIN_5 equ 213
        MM_MOTU_MTPII_NET_MIDIOUT_5 equ 213
        MM_MOTU_MTPII_NET_MIDIIN_6 equ 214
        MM_MOTU_MTPII_NET_MIDIOUT_6 equ 214
        MM_MOTU_MTPII_NET_MIDIIN_7 equ 215
        MM_MOTU_MTPII_NET_MIDIOUT_7 equ 215
        MM_MOTU_MTPII_NET_MIDIIN_8 equ 216
        MM_MOTU_MTPII_NET_MIDIOUT_8 equ 216
        MM_MOTU_MXP_MIDIIN_MIDIOUT_ALL equ 300
        MM_MOTU_MXP_MIDIIN_SYNC equ 300
        MM_MOTU_MXP_MIDIIN_MIDIIN_1 equ 301
        MM_MOTU_MXP_MIDIIN_MIDIOUT_1 equ 301
        MM_MOTU_MXP_MIDIIN_MIDIIN_2 equ 302
        MM_MOTU_MXP_MIDIIN_MIDIOUT_2 equ 302
        MM_MOTU_MXP_MIDIIN_MIDIIN_3 equ 303
        MM_MOTU_MXP_MIDIIN_MIDIOUT_3 equ 303
        MM_MOTU_MXP_MIDIIN_MIDIIN_4 equ 304
        MM_MOTU_MXP_MIDIIN_MIDIOUT_4 equ 304
        MM_MOTU_MXP_MIDIIN_MIDIIN_5 equ 305
        MM_MOTU_MXP_MIDIIN_MIDIOUT_5 equ 305
        MM_MOTU_MXP_MIDIIN_MIDIIN_6 equ 306
        MM_MOTU_MXP_MIDIIN_MIDIOUT_6 equ 306
        MM_MOTU_MXPMPU_MIDIOUT_ALL equ 400
        MM_MOTU_MXPMPU_MIDIIN_SYNC equ 400
        MM_MOTU_MXPMPU_MIDIIN_1 equ 401
        MM_MOTU_MXPMPU_MIDIOUT_1 equ 401
        MM_MOTU_MXPMPU_MIDIIN_2 equ 402
        MM_MOTU_MXPMPU_MIDIOUT_2 equ 402
        MM_MOTU_MXPMPU_MIDIIN_3 equ 403
        MM_MOTU_MXPMPU_MIDIOUT_3 equ 403
        MM_MOTU_MXPMPU_MIDIIN_4 equ 404
        MM_MOTU_MXPMPU_MIDIOUT_4 equ 404
        MM_MOTU_MXPMPU_MIDIIN_5 equ 405
        MM_MOTU_MXPMPU_MIDIOUT_5 equ 405
        MM_MOTU_MXPMPU_MIDIIN_6 equ 406
        MM_MOTU_MXPMPU_MIDIOUT_6 equ 406
        MM_MOTU_MXN_MIDIOUT_ALL equ 500
        MM_MOTU_MXN_MIDIIN_SYNC equ 500
        MM_MOTU_MXN_MIDIIN_1 equ 501
        MM_MOTU_MXN_MIDIOUT_1 equ 501
        MM_MOTU_MXN_MIDIIN_2 equ 502
        MM_MOTU_MXN_MIDIOUT_2 equ 502
        MM_MOTU_MXN_MIDIIN_3 equ 503
        MM_MOTU_MXN_MIDIOUT_3 equ 503
        MM_MOTU_MXN_MIDIIN_4 equ 504
        MM_MOTU_MXN_MIDIOUT_4 equ 504
        MM_MOTU_FLYER_MIDI_IN_SYNC equ 600
        MM_MOTU_FLYER_MIDI_IN_A equ 601
        MM_MOTU_FLYER_MIDI_OUT_A equ 601
        MM_MOTU_FLYER_MIDI_IN_B equ 602
        MM_MOTU_FLYER_MIDI_OUT_B equ 602
        MM_MOTU_PKX_MIDI_IN_SYNC equ 700
        MM_MOTU_PKX_MIDI_IN_A equ 701
        MM_MOTU_PKX_MIDI_OUT_A equ 701
        MM_MOTU_PKX_MIDI_IN_B equ 702
        MM_MOTU_PKX_MIDI_OUT_B equ 702
        MM_MOTU_DTX_MIDI_IN_SYNC equ 800
        MM_MOTU_DTX_MIDI_IN_A equ 801
        MM_MOTU_DTX_MIDI_OUT_A equ 801
        MM_MOTU_DTX_MIDI_IN_B equ 802
        MM_MOTU_DTX_MIDI_OUT_B equ 802
        MM_MOTU_MTPAV_MIDIOUT_ALL equ 900
        MM_MOTU_MTPAV_MIDIIN_SYNC equ 900
        MM_MOTU_MTPAV_MIDIIN_1 equ 901
        MM_MOTU_MTPAV_MIDIOUT_1 equ 901
        MM_MOTU_MTPAV_MIDIIN_2 equ 902
        MM_MOTU_MTPAV_MIDIOUT_2 equ 902
        MM_MOTU_MTPAV_MIDIIN_3 equ 903
        MM_MOTU_MTPAV_MIDIOUT_3 equ 903
        MM_MOTU_MTPAV_MIDIIN_4 equ 904
        MM_MOTU_MTPAV_MIDIOUT_4 equ 904
        MM_MOTU_MTPAV_MIDIIN_5 equ 905
        MM_MOTU_MTPAV_MIDIOUT_5 equ 905
        MM_MOTU_MTPAV_MIDIIN_6 equ 906
        MM_MOTU_MTPAV_MIDIOUT_6 equ 906
        MM_MOTU_MTPAV_MIDIIN_7 equ 907
        MM_MOTU_MTPAV_MIDIOUT_7 equ 907
        MM_MOTU_MTPAV_MIDIIN_8 equ 908
        MM_MOTU_MTPAV_MIDIOUT_8 equ 908
        MM_MOTU_MTPAV_NET_MIDIIN_1 equ 909
        MM_MOTU_MTPAV_NET_MIDIOUT_1 equ 909
        MM_MOTU_MTPAV_NET_MIDIIN_2 equ 910
        MM_MOTU_MTPAV_NET_MIDIOUT_2 equ 910
        MM_MOTU_MTPAV_NET_MIDIIN_3 equ 911
        MM_MOTU_MTPAV_NET_MIDIOUT_3 equ 911
        MM_MOTU_MTPAV_NET_MIDIIN_4 equ 912
        MM_MOTU_MTPAV_NET_MIDIOUT_4 equ 912
        MM_MOTU_MTPAV_NET_MIDIIN_5 equ 913
        MM_MOTU_MTPAV_NET_MIDIOUT_5 equ 913
        MM_MOTU_MTPAV_NET_MIDIIN_6 equ 914
        MM_MOTU_MTPAV_NET_MIDIOUT_6 equ 914
        MM_MOTU_MTPAV_NET_MIDIIN_7 equ 915
        MM_MOTU_MTPAV_NET_MIDIOUT_7 equ 915
        MM_MOTU_MTPAV_NET_MIDIIN_8 equ 916
        MM_MOTU_MTPAV_NET_MIDIOUT_8 equ 916
        MM_MOTU_MTPAV_MIDIIN_ADAT equ 917
        MM_MOTU_MTPAV_MIDIOUT_ADAT equ 917
        MM_MOTU_MXPXT_MIDIIN_SYNC equ 1000
        MM_MOTU_MXPXT_MIDIOUT_ALL equ 1000
        MM_MOTU_MXPXT_MIDIIN_1 equ 1001
        MM_MOTU_MXPXT_MIDIOUT_1 equ 1001
        MM_MOTU_MXPXT_MIDIOUT_2 equ 1002
        MM_MOTU_MXPXT_MIDIIN_2 equ 1002
        MM_MOTU_MXPXT_MIDIIN_3 equ 1003
        MM_MOTU_MXPXT_MIDIOUT_3 equ 1003
        MM_MOTU_MXPXT_MIDIIN_4 equ 1004
        MM_MOTU_MXPXT_MIDIOUT_4 equ 1004
        MM_MOTU_MXPXT_MIDIIN_5 equ 1005
        MM_MOTU_MXPXT_MIDIOUT_5 equ 1005
        MM_MOTU_MXPXT_MIDIOUT_6 equ 1006
        MM_MOTU_MXPXT_MIDIIN_6 equ 1006
        MM_MOTU_MXPXT_MIDIOUT_7 equ 1007
        MM_MOTU_MXPXT_MIDIIN_7 equ 1007
        MM_MOTU_MXPXT_MIDIOUT_8 equ 1008
        MM_MOTU_MXPXT_MIDIIN_8 equ 1008
        MM_WORKBIT_MIXER equ 1
        MM_WORKBIT_WAVEOUT equ 2
        MM_WORKBIT_WAVEIN equ 3
        MM_WORKBIT_MIDIIN equ 4
        MM_WORKBIT_MIDIOUT equ 5
        MM_WORKBIT_FMSYNTH equ 6
        MM_WORKBIT_AUX equ 7
        MM_WORKBIT_JOYSTICK equ 8
        MM_OSITECH_TRUMPCARD equ 1
        MM_MIRO_MOVIEPRO equ 1
        MM_MIRO_VIDEOD1 equ 2
        MM_MIRO_VIDEODC1TV equ 3
        MM_MIRO_VIDEOTD equ 4
        MM_MIRO_DC30_WAVEOUT equ 5
        MM_MIRO_DC30_WAVEIN equ 6
        MM_MIRO_DC30_MIX equ 7
        MM_ISOLUTION_PASCAL equ 1
        MM_VOICEMIXER equ 1
        ROCKWELL_WA1_WAVEIN equ 100
        ROCKWELL_WA1_WAVEOUT equ 101
        ROCKWELL_WA1_SYNTH equ 102
        ROCKWELL_WA1_MIXER equ 103
        ROCKWELL_WA1_MPU401_IN equ 104
        ROCKWELL_WA1_MPU401_OUT equ 105
        ROCKWELL_WA2_WAVEIN equ 200
        ROCKWELL_WA2_WAVEOUT equ 201
        ROCKWELL_WA2_SYNTH equ 202
        ROCKWELL_WA2_MIXER equ 203
        ROCKWELL_WA2_MPU401_IN equ 204
        ROCKWELL_WA2_MPU401_OUT equ 205
        MM_VOXWARE_CODEC equ 1
        MM_NORTEL_MPXAC_WAVEIN equ 1
        MM_NORTEL_MPXAC_WAVEOUT equ 2
        MM_ADDX_PCTV_DIGITALMIX equ 1
        MM_ADDX_PCTV_WAVEIN equ 2
        MM_ADDX_PCTV_WAVEOUT equ 3
        MM_ADDX_PCTV_MIXER equ 4
        MM_ADDX_PCTV_AUX_CD equ 5
        MM_ADDX_PCTV_AUX_LINE equ 6
        MM_WILDCAT_AUTOSCOREMIDIIN equ 1
        MM_RHETOREX_WAVEIN equ 1
        MM_RHETOREX_WAVEOUT equ 2
        MM_BTV_WAVEIN equ 1
        MM_BTV_WAVEOUT equ 2
        MM_BTV_MIDIIN equ 3
        MM_BTV_MIDIOUT equ 4
        MM_BTV_MIDISYNTH equ 5
        MM_BTV_AUX_LINE equ 6
        MM_BTV_AUX_MIC equ 7
        MM_BTV_AUX_CD equ 8
        MM_BTV_DIGITALIN equ 9
        MM_BTV_DIGITALOUT equ 10
        MM_BTV_MIDIWAVESTREAM equ 11
        MM_BTV_MIXER equ 12
        MM_ENSONIQ_SOUNDSCAPE equ 10h
        MM_SOUNDSCAPE_WAVEOUT equ MM_ENSONIQ_SOUNDSCAPE + 1
        MM_SOUNDSCAPE_WAVEOUT_AUX equ MM_ENSONIQ_SOUNDSCAPE + 2
        MM_SOUNDSCAPE_WAVEIN equ MM_ENSONIQ_SOUNDSCAPE + 3
        MM_SOUNDSCAPE_MIDIOUT equ MM_ENSONIQ_SOUNDSCAPE + 4
        MM_SOUNDSCAPE_MIDIIN equ MM_ENSONIQ_SOUNDSCAPE + 5
        MM_SOUNDSCAPE_SYNTH equ MM_ENSONIQ_SOUNDSCAPE + 6
        MM_SOUNDSCAPE_MIXER equ MM_ENSONIQ_SOUNDSCAPE + 7
        MM_SOUNDSCAPE_AUX equ MM_ENSONIQ_SOUNDSCAPE + 8
        MM_NVIDIA_WAVEOUT equ 1
        MM_NVIDIA_WAVEIN equ 2
        MM_NVIDIA_MIDIOUT equ 3
        MM_NVIDIA_MIDIIN equ 4
        MM_NVIDIA_GAMEPORT equ 5
        MM_NVIDIA_MIXER equ 6
        MM_NVIDIA_AUX equ 7
        MM_OKSORI_BASE equ 0
        MM_OKSORI_OSR8_WAVEOUT equ MM_OKSORI_BASE + 1
        MM_OKSORI_OSR8_WAVEIN equ MM_OKSORI_BASE + 2
        MM_OKSORI_OSR16_WAVEOUT equ MM_OKSORI_BASE + 3
        MM_OKSORI_OSR16_WAVEIN equ MM_OKSORI_BASE + 4
        MM_OKSORI_FM_OPL4 equ MM_OKSORI_BASE + 5
        MM_OKSORI_MIX_MASTER equ MM_OKSORI_BASE + 6
        MM_OKSORI_MIX_WAVE equ MM_OKSORI_BASE + 7
        MM_OKSORI_MIX_FM equ MM_OKSORI_BASE + 8
        MM_OKSORI_MIX_LINE equ MM_OKSORI_BASE + 9
        MM_OKSORI_MIX_CD equ MM_OKSORI_BASE + 10
        MM_OKSORI_MIX_MIC equ MM_OKSORI_BASE + 11
        MM_OKSORI_MIX_ECHO equ MM_OKSORI_BASE + 12
        MM_OKSORI_MIX_AUX1 equ MM_OKSORI_BASE + 13
        MM_OKSORI_MIX_LINE1 equ MM_OKSORI_BASE + 14
        MM_OKSORI_EXT_MIC1 equ MM_OKSORI_BASE + 15
        MM_OKSORI_EXT_MIC2 equ MM_OKSORI_BASE + 16
        MM_OKSORI_MIDIOUT equ MM_OKSORI_BASE + 17
        MM_OKSORI_MIDIIN equ MM_OKSORI_BASE + 18
        MM_OKSORI_MPEG_CDVISION equ MM_OKSORI_BASE + 19
        MM_DIACOUSTICS_DRUM_ACTION equ 1
        MM_KAY_ELEMETRICS_CSL equ 4300h
        MM_KAY_ELEMETRICS_CSL_DAT equ 4308h
        MM_KAY_ELEMETRICS_CSL_4CHANNEL equ 4309h
        MM_CRYSTAL_CS4232_WAVEIN equ 1
        MM_CRYSTAL_CS4232_WAVEOUT equ 2
        MM_CRYSTAL_CS4232_WAVEMIXER equ 3
        MM_CRYSTAL_CS4232_WAVEAUX_AUX1 equ 4
        MM_CRYSTAL_CS4232_WAVEAUX_AUX2 equ 5
        MM_CRYSTAL_CS4232_WAVEAUX_LINE equ 6
        MM_CRYSTAL_CS4232_WAVEAUX_MONO equ 7
        MM_CRYSTAL_CS4232_WAVEAUX_MASTER equ 8
        MM_CRYSTAL_CS4232_MIDIIN equ 9
        MM_CRYSTAL_CS4232_MIDIOUT equ 10
        MM_CRYSTAL_CS4232_INPUTGAIN_AUX1 equ 13
        MM_CRYSTAL_CS4232_INPUTGAIN_LOOP equ 14
        MM_CRYSTAL_SOUND_FUSION_WAVEIN equ 21
        MM_CRYSTAL_SOUND_FUSION_WAVEOUT equ 22
        MM_CRYSTAL_SOUND_FUSION_MIXER equ 23
        MM_CRYSTAL_SOUND_FUSION_MIDIIN equ 24
        MM_CRYSTAL_SOUND_FUSION_MIDIOUT equ 25
        MM_CRYSTAL_SOUND_FUSION_JOYSTICK equ 26
        MM_QUARTERDECK_LHWAVEIN equ 0
        MM_QUARTERDECK_LHWAVEOUT equ 1
        MM_TDK_MW_MIDI_SYNTH equ 1
        MM_TDK_MW_MIDI_IN equ 2
        MM_TDK_MW_MIDI_OUT equ 3
        MM_TDK_MW_WAVE_IN equ 4
        MM_TDK_MW_WAVE_OUT equ 5
        MM_TDK_MW_AUX equ 6
        MM_TDK_MW_MIXER equ 10
        MM_TDK_MW_AUX_MASTER equ 100
        MM_TDK_MW_AUX_BASS equ 101
        MM_TDK_MW_AUX_TREBLE equ 102
        MM_TDK_MW_AUX_MIDI_VOL equ 103
        MM_TDK_MW_AUX_WAVE_VOL equ 104
        MM_TDK_MW_AUX_WAVE_RVB equ 105
        MM_TDK_MW_AUX_WAVE_CHR equ 106
        MM_TDK_MW_AUX_VOL equ 107
        MM_TDK_MW_AUX_RVB equ 108
        MM_TDK_MW_AUX_CHR equ 109
        MM_DIGITAL_AUDIO_LABS_TC equ 01h
        MM_DIGITAL_AUDIO_LABS_DOC equ 02h
        MM_DIGITAL_AUDIO_LABS_V8 equ 10h
        MM_DIGITAL_AUDIO_LABS_CPRO equ 11h
        MM_DIGITAL_AUDIO_LABS_VP equ 12h
        MM_DIGITAL_AUDIO_LABS_CDLX equ 13h
        MM_DIGITAL_AUDIO_LABS_CTDIF equ 14h
        MM_SEERSYS_SEERSYNTH equ 1
        MM_SEERSYS_SEERWAVE equ 2
        MM_SEERSYS_SEERMIX equ 3
        MM_SEERSYS_WAVESYNTH equ 4
        MM_SEERSYS_WAVESYNTH_WG equ 5
        MM_SEERSYS_REALITY equ 6
        MM_OSPREY_1000WAVEIN equ 1
        MM_OSPREY_1000WAVEOUT equ 2
        MM_SOUNDESIGNS_WAVEIN equ 1
        MM_SOUNDESIGNS_WAVEOUT equ 2
        MM_SSP_SNDFESWAVEIN equ 1
        MM_SSP_SNDFESWAVEOUT equ 2
        MM_SSP_SNDFESMIDIIN equ 3
        MM_SSP_SNDFESMIDIOUT equ 4
        MM_SSP_SNDFESSYNTH equ 5
        MM_SSP_SNDFESMIX equ 6
        MM_SSP_SNDFESAUX equ 7
        MM_ECS_AADF_MIDI_IN equ 10
        MM_ECS_AADF_MIDI_OUT equ 11
        MM_ECS_AADF_WAVE2MIDI_IN equ 12
        MM_AMD_INTERWAVE_WAVEIN equ 1
        MM_AMD_INTERWAVE_WAVEOUT equ 2
        MM_AMD_INTERWAVE_SYNTH equ 3
        MM_AMD_INTERWAVE_MIXER1 equ 4
        MM_AMD_INTERWAVE_MIXER2 equ 5
        MM_AMD_INTERWAVE_JOYSTICK equ 6
        MM_AMD_INTERWAVE_EX_CD equ 7
        MM_AMD_INTERWAVE_MIDIIN equ 8
        MM_AMD_INTERWAVE_MIDIOUT equ 9
        MM_AMD_INTERWAVE_AUX1 equ 10
        MM_AMD_INTERWAVE_AUX2 equ 11
        MM_AMD_INTERWAVE_AUX_MIC equ 12
        MM_AMD_INTERWAVE_AUX_CD equ 13
        MM_AMD_INTERWAVE_MONO_IN equ 14
        MM_AMD_INTERWAVE_MONO_OUT equ 15
        MM_AMD_INTERWAVE_EX_TELEPHONY equ 16
        MM_AMD_INTERWAVE_WAVEOUT_BASE equ 17
        MM_AMD_INTERWAVE_WAVEOUT_TREBLE equ 18
        MM_AMD_INTERWAVE_STEREO_ENHANCED equ 19
        MM_COREDYNAMICS_DYNAMIXHR equ 1
        MM_COREDYNAMICS_DYNASONIX_SYNTH equ 2
        MM_COREDYNAMICS_DYNASONIX_MIDI_IN equ 3
        MM_COREDYNAMICS_DYNASONIX_MIDI_OUT equ 4
        MM_COREDYNAMICS_DYNASONIX_WAVE_IN equ 5
        MM_COREDYNAMICS_DYNASONIX_WAVE_OUT equ 6
        MM_COREDYNAMICS_DYNASONIX_AUDIO_IN equ 7
        MM_COREDYNAMICS_DYNASONIX_AUDIO_OUT equ 8
        MM_COREDYNAMICS_DYNAGRAFX_VGA equ 9
        MM_COREDYNAMICS_DYNAGRAFX_WAVE_IN equ 10
        MM_COREDYNAMICS_DYNAGRAFX_WAVE_OUT equ 11
        MM_CANAM_CBXWAVEOUT equ 1
        MM_CANAM_CBXWAVEIN equ 2
        MM_SOFTSOUND_CODEC equ 1
        MM_NORRIS_VOICELINK equ 1
        MM_DDD_MIDILINK_MIDIIN equ 1
        MM_DDD_MIDILINK_MIDIOUT equ 2
        MM_EUPHONICS_AUX_CD equ 1
        MM_EUPHONICS_AUX_LINE equ 2
        MM_EUPHONICS_AUX_MASTER equ 3
        MM_EUPHONICS_AUX_MIC equ 4
        MM_EUPHONICS_AUX_MIDI equ 5
        MM_EUPHONICS_AUX_WAVE equ 6
        MM_EUPHONICS_FMSYNTH_MONO equ 7
        MM_EUPHONICS_FMSYNTH_STEREO equ 8
        MM_EUPHONICS_MIDIIN equ 9
        MM_EUPHONICS_MIDIOUT equ 10
        MM_EUPHONICS_MIXER equ 11
        MM_EUPHONICS_WAVEIN equ 12
        MM_EUPHONICS_WAVEOUT equ 13
        MM_EUPHONICS_EUSYNTH equ 14
        CRYSTAL_NET_SFM_CODEC equ 1
        MM_CHROMATIC_M1 equ 0001h
        MM_CHROMATIC_M1_WAVEIN equ 0002h
        MM_CHROMATIC_M1_WAVEOUT equ 0003h
        MM_CHROMATIC_M1_FMSYNTH equ 0004h
        MM_CHROMATIC_M1_MIXER equ 0005h
        MM_CHROMATIC_M1_AUX equ 0006h
        MM_CHROMATIC_M1_AUX_CD equ 0007h
        MM_CHROMATIC_M1_MIDIIN equ 0008h
        MM_CHROMATIC_M1_MIDIOUT equ 0009h
        MM_CHROMATIC_M1_WTSYNTH equ 0010h
        MM_CHROMATIC_M1_MPEGWAVEIN equ 0011h
        MM_CHROMATIC_M1_MPEGWAVEOUT equ 0012h
        MM_CHROMATIC_M2 equ 0013h
        MM_CHROMATIC_M2_WAVEIN equ 0014h
        MM_CHROMATIC_M2_WAVEOUT equ 0015h
        MM_CHROMATIC_M2_FMSYNTH equ 0016h
        MM_CHROMATIC_M2_MIXER equ 0017h
        MM_CHROMATIC_M2_AUX equ 0018h
        MM_CHROMATIC_M2_AUX_CD equ 0019h
        MM_CHROMATIC_M2_MIDIIN equ 0020h
        MM_CHROMATIC_M2_MIDIOUT equ 0021h
        MM_CHROMATIC_M2_WTSYNTH equ 0022h
        MM_CHROMATIC_M2_MPEGWAVEIN equ 0023h
        MM_CHROMATIC_M2_MPEGWAVEOUT equ 0024h
        MM_VIENNASYS_TSP_WAVE_DRIVER equ 1
        MM_CONNECTIX_VIDEC_CODEC equ 1
        MM_GADGETLABS_WAVE44_WAVEIN equ 1
        MM_GADGETLABS_WAVE44_WAVEOUT equ 2
        MM_GADGETLABS_WAVE42_WAVEIN equ 3
        MM_GADGETLABS_WAVE42_WAVEOUT equ 4
        MM_GADGETLABS_WAVE4_MIDIIN equ 5
        MM_GADGETLABS_WAVE4_MIDIOUT equ 6
        MM_FRONTIER_WAVECENTER_MIDIIN equ 1
        MM_FRONTIER_WAVECENTER_MIDIOUT equ 2
        MM_FRONTIER_WAVECENTER_WAVEIN equ 3
        MM_FRONTIER_WAVECENTER_WAVEOUT equ 4
        MM_VIONA_QVINPCI_MIXER equ 1
        MM_VIONA_QVINPCI_WAVEIN equ 2
        MM_VIONAQVINPCI_WAVEOUT equ 3
        MM_VIONA_BUSTER_MIXER equ 4
        MM_VIONA_CINEMASTER_MIXER equ 5
        MM_VIONA_CONCERTO_MIXER equ 6
        MM_CASIO_WP150_MIDIOUT equ 1
        MM_CASIO_WP150_MIDIIN equ 2
        MM_CASIO_LSG_MIDIOUT equ 3
        MM_DIMD_PLATFORM equ 0
        MM_DIMD_DIRSOUND equ 1
        MM_DIMD_VIRTMPU equ 2
        MM_DIMD_VIRTSB equ 3
        MM_DIMD_VIRTJOY equ 4
        MM_DIMD_WAVEIN equ 5
        MM_DIMD_WAVEOUT equ 6
        MM_DIMD_MIDIIN equ 7
        MM_DIMD_MIDIOUT equ 8
        MM_DIMD_AUX_LINE equ 9
        MM_DIMD_MIXER equ 10
        MM_DIMD_WSS_WAVEIN equ 14
        MM_DIMD_WSS_WAVEOUT equ 15
        MM_DIMD_WSS_MIXER equ 17
        MM_DIMD_WSS_AUX equ 21
        MM_DIMD_WSS_SYNTH equ 76
        MM_S3_WAVEOUT equ 1
        MM_S3_WAVEIN equ 2
        MM_S3_MIDIOUT equ 3
        MM_S3_MIDIIN equ 4
        MM_S3_FMSYNTH equ 5
        MM_S3_MIXER equ 6
        MM_S3_AUX equ 7
        MM_VKC_MPU401_MIDIIN equ 0100h
        MM_VKC_SERIAL_MIDIIN equ 0101h
        MM_VKC_MPU401_MIDIOUT equ 0200h
        MM_VKC_SERIAL_MIDIOUT equ 0201h
        MM_ZEFIRO_ZA2 equ 2
        MM_FHGIIS_MPEGLAYER3_DECODE equ 9
        MM_FHGIIS_MPEGLAYER3 equ 10
        MM_FHGIIS_MPEGLAYER3_LITE equ 10
        MM_FHGIIS_MPEGLAYER3_BASIC equ 11
        MM_FHGIIS_MPEGLAYER3_ADVANCED equ 12
        MM_FHGIIS_MPEGLAYER3_PROFESSIONAL equ 13
        MM_FHGIIS_MPEGLAYER3_ADVANCEDPLUS equ 14
        MM_QUICKNET_PJWAVEIN equ 1
        MM_QUICKNET_PJWAVEOUT equ 2
        MM_SICRESOURCE_SSO3D equ 2
        MM_SICRESOURCE_SSOW3DI equ 3
        MM_NEOMAGIC_SYNTH equ 1
        MM_NEOMAGIC_WAVEOUT equ 2
        MM_NEOMAGIC_WAVEIN equ 3
        MM_NEOMAGIC_MIDIOUT equ 4
        MM_NEOMAGIC_MIDIIN equ 5
        MM_NEOMAGIC_AUX equ 6
        MM_NEOMAGIC_MW3DX_WAVEOUT equ 10
        MM_NEOMAGIC_MW3DX_WAVEIN equ 11
        MM_NEOMAGIC_MW3DX_MIDIOUT equ 12
        MM_NEOMAGIC_MW3DX_MIDIIN equ 13
        MM_NEOMAGIC_MW3DX_FMSYNTH equ 14
        MM_NEOMAGIC_MW3DX_GMSYNTH equ 15
        MM_NEOMAGIC_MW3DX_MIXER equ 16
        MM_NEOMAGIC_MW3DX_AUX equ 17
        MM_NEOMAGIC_MWAVE_WAVEOUT equ 20
        MM_NEOMAGIC_MWAVE_WAVEIN equ 21
        MM_NEOMAGIC_MWAVE_MIDIOUT equ 22
        MM_NEOMAGIC_MWAVE_MIDIIN equ 23
        MM_NEOMAGIC_MWAVE_MIXER equ 24
        MM_NEOMAGIC_MWAVE_AUX equ 25
        MM_MERGING_MPEGL3 equ 1
        MM_XIRLINK_VISIONLINK equ 1
        MM_OTI_611WAVEIN equ 5
        MM_OTI_611WAVEOUT equ 6
        MM_OTI_611MIXER equ 7
        MM_OTI_611MIDIN equ 12h
        MM_OTI_611MIDIOUT equ 13h
        MM_AUREAL_AU8820 equ 16
        MM_AU8820_SYNTH equ 17
        MM_AU8820_WAVEOUT equ 18
        MM_AU8820_WAVEIN equ 19
        MM_AU8820_MIXER equ 20
        MM_AU8820_AUX equ 21
        MM_AU8820_MIDIOUT equ 22
        MM_AU8820_MIDIIN equ 23
        MM_AUREAL_AU8830 equ 32
        MM_AU8830_SYNTH equ 33
        MM_AU8830_WAVEOUT equ 34
        MM_AU8830_WAVEIN equ 35
        MM_AU8830_MIXER equ 36
        MM_AU8830_AUX equ 37
        MM_AU8830_MIDIOUT equ 38
        MM_AU8830_MIDIIN equ 39
        MM_VIVO_AUDIO_CODEC equ 1
        MM_SHARP_MDC_MIDI_SYNTH equ 1
        MM_SHARP_MDC_MIDI_IN equ 2
        MM_SHARP_MDC_MIDI_OUT equ 3
        MM_SHARP_MDC_WAVE_IN equ 4
        MM_SHARP_MDC_WAVE_OUT equ 5
        MM_SHARP_MDC_AUX equ 6
        MM_SHARP_MDC_MIXER equ 10
        MM_SHARP_MDC_AUX_MASTER equ 100
        MM_SHARP_MDC_AUX_BASS equ 101
        MM_SHARP_MDC_AUX_TREBLE equ 102
        MM_SHARP_MDC_AUX_MIDI_VOL equ 103
        MM_SHARP_MDC_AUX_WAVE_VOL equ 104
        MM_SHARP_MDC_AUX_WAVE_RVB equ 105
        MM_SHARP_MDC_AUX_WAVE_CHR equ 106
        MM_SHARP_MDC_AUX_VOL equ 107
        MM_SHARP_MDC_AUX_RVB equ 108
        MM_SHARP_MDC_AUX_CHR equ 109
        MM_LUCENT_ACM_G723 equ 0
        MM_ATT_G729A equ 1
        MM_MARIAN_ARC44WAVEIN equ 1
        MM_MARIAN_ARC44WAVEOUT equ 2
        MM_MARIAN_PRODIF24WAVEIN equ 3
        MM_MARIAN_PRODIF24WAVEOUT equ 4
        MM_MARIAN_ARC88WAVEIN equ 5
        MM_MARIAN_ARC88WAVEOUT equ 6
        MM_BCB_NETBOARD_10 equ 1
        MM_BCB_TT75_10 equ 2
        MM_MOTIONPIXELS_MVI2 equ 1
        MM_QDESIGN_ACM_MPEG equ 1
        MM_QDESIGN_ACM_QDESIGN_MUSIC equ 2
        MM_NMP_CCP_WAVEIN equ 1
        MM_NMP_CCP_WAVEOUT equ 2
        MM_NMP_ACM_AMR equ 10
        MM_DF_ACM_G726 equ 1
        MM_DF_ACM_GSM610 equ 2
        MM_BERCOS_WAVEIN equ 1
        MM_BERCOS_MIXER equ 2
        MM_BERCOS_WAVEOUT equ 3
        MM_ONLIVE_MPCODEC equ 1
        MM_PHONET_PP_WAVEOUT equ 1
        MM_PHONET_PP_WAVEIN equ 2
        MM_PHONET_PP_MIXER equ 3
        MM_FTR_ENCODER_WAVEIN equ 1
        MM_FTR_ACM equ 2
        MM_ENET_T2000_LINEIN equ 1
        MM_ENET_T2000_LINEOUT equ 2
        MM_ENET_T2000_HANDSETIN equ 3
        MM_ENET_T2000_HANDSETOUT equ 4
        MM_EMAGIC_UNITOR8 equ 1
        MM_SIPROLAB_ACELPNET equ 1
        MM_DICTAPHONE_G726 equ 1
        MM_RZS_ACM_TUBGSM equ 1
        MM_EES_PCMIDI14 equ 1
        MM_EES_PCMIDI14_IN equ 2
        MM_EES_PCMIDI14_OUT1 equ 3
        MM_EES_PCMIDI14_OUT2 equ 4
        MM_EES_PCMIDI14_OUT3 equ 5
        MM_EES_PCMIDI14_OUT4 equ 6
        MM_HAFTMANN_LPTDAC2 equ 1
        MM_LUCID_PCI24WAVEIN equ 1
        MM_LUCID_PCI24WAVEOUT equ 2
        MM_HEADSPACE_HAESYNTH equ 1
        MM_HEADSPACE_HAEWAVEOUT equ 2
        MM_HEADSPACE_HAEWAVEIN equ 3
        MM_HEADSPACE_HAEMIXER equ 4
        MM_UNISYS_ACM_NAP equ 1
        MM_LUMINOSITI_SCWAVEIN equ 1
        MM_LUMINOSITI_SCWAVEOUT equ 2
        MM_LUMINOSITI_SCWAVEMIX equ 3
        MM_ACTIVEVOICE_ACM_VOXADPCM equ 1
        MM_DTS_DS equ 1
        MM_SOFTLAB_NSK_FRW_WAVEIN equ 1
        MM_SOFTLAB_NSK_FRW_WAVEOUT equ 2
        MM_SOFTLAB_NSK_FRW_MIXER equ 3
        MM_SOFTLAB_NSK_FRW_AUX equ 4
        MM_FORTEMEDIA_WAVEIN equ 1
        MM_FORTEMEDIA_WAVEOUT equ 2
        MM_FORTEMEDIA_FMSYNC equ 3
        MM_FORTEMEDIA_MIXER equ 4
        MM_FORTEMEDIA_AUX equ 5
        MM_SONORUS_STUDIO equ 1
        MM_I_LINK_VOICE_CODER equ 1
        MM_SELSIUS_SYSTEMS_RTPWAVEOUT equ 1
        MM_SELSIUS_SYSTEMS_RTPWAVEIN equ 2
        MM_ADMOS_FM_SYNTH equ 1
        MM_ADMOS_QS3AMIDIOUT equ 2
        MM_ADMOS_QS3AMIDIIN equ 3
        MM_ADMOS_QS3AWAVEOUT equ 4
        MM_ADMOS_QS3AWAVEIN equ 5
        MM_LEXICON_STUDIO_WAVE_OUT equ 1
        MM_LEXICON_STUDIO_WAVE_IN equ 2
        MM_SGI_320_WAVEIN equ 1
        MM_SGI_320_WAVEOUT equ 2
        MM_SGI_320_MIXER equ 3
        MM_SGI_540_WAVEIN equ 4
        MM_SGI_540_WAVEOUT equ 5
        MM_SGI_540_MIXER equ 6
        MM_SGI_RAD_ADATMONO1_WAVEIN equ 7
        MM_SGI_RAD_ADATMONO2_WAVEIN equ 8
        MM_SGI_RAD_ADATMONO3_WAVEIN equ 9
        MM_SGI_RAD_ADATMONO4_WAVEIN equ 10
        MM_SGI_RAD_ADATMONO5_WAVEIN equ 11
        MM_SGI_RAD_ADATMONO6_WAVEIN equ 12
        MM_SGI_RAD_ADATMONO7_WAVEIN equ 13
        MM_SGI_RAD_ADATMONO8_WAVEIN equ 14
        MM_SGI_RAD_ADATSTEREO12_WAVEIN equ 15
        MM_SGI_RAD_ADATSTEREO34_WAVEIN equ 16
        MM_SGI_RAD_ADATSTEREO56_WAVEIN equ 17
        MM_SGI_RAD_ADATSTEREO78_WAVEIN equ 18
        MM_SGI_RAD_ADAT8CHAN_WAVEIN equ 19
        MM_SGI_RAD_ADATMONO1_WAVEOUT equ 20
        MM_SGI_RAD_ADATMONO2_WAVEOUT equ 21
        MM_SGI_RAD_ADATMONO3_WAVEOUT equ 22
        MM_SGI_RAD_ADATMONO4_WAVEOUT equ 23
        MM_SGI_RAD_ADATMONO5_WAVEOUT equ 24
        MM_SGI_RAD_ADATMONO6_WAVEOUT equ 25
        MM_SGI_RAD_ADATMONO7_WAVEOUT equ 26
        MM_SGI_RAD_ADATMONO8_WAVEOUT equ 27
        MM_SGI_RAD_ADATSTEREO12_WAVEOUT equ 28
        MM_SGI_RAD_ADATSTEREO32_WAVEOUT equ 29
        MM_SGI_RAD_ADATSTEREO56_WAVEOUT equ 30
        MM_SGI_RAD_ADATSTEREO78_WAVEOUT equ 31
        MM_SGI_RAD_ADAT8CHAN_WAVEOUT equ 32
        MM_SGI_RAD_AESMONO1_WAVEIN equ 33
        MM_SGI_RAD_AESMONO2_WAVEIN equ 34
        MM_SGI_RAD_AESSTEREO_WAVEIN equ 35
        MM_SGI_RAD_AESMONO1_WAVEOUT equ 36
        MM_SGI_RAD_AESMONO2_WAVEOUT equ 37
        MM_SGI_RAD_AESSTEREO_WAVEOUT equ 38
        MM_IPI_ACM_HSX equ 1
        MM_IPI_ACM_RPELP equ 2
        MM_IPI_WF_ASSS equ 3
        MM_IPI_AT_WAVEOUT equ 4
        MM_IPI_AT_WAVEIN equ 5
        MM_IPI_AT_MIXER equ 6
        MM_ICE_WAVEOUT equ 1
        MM_ICE_WAVEIN equ 2
        MM_ICE_MTWAVEOUT equ 3
        MM_ICE_MTWAVEIN equ 4
        MM_ICE_MIDIOUT1 equ 5
        MM_ICE_MIDIIN1 equ 6
        MM_ICE_MIDIOUT2 equ 7
        MM_ICE_MIDIIN2 equ 8
        MM_ICE_SYNTH equ 9
        MM_ICE_MIXER equ 10
        MM_ICE_AUX equ 11
        MM_VQST_VQC1 equ 1
        MM_VQST_VQC2 equ 2
        MM_ETEK_KWIKMIDI_MIDIIN equ 1
        MM_ETEK_KWIKMIDI_MIDIOUT equ 2
        MM_INTERNET_SSW_MIDIOUT equ 10
        MM_INTERNET_SSW_MIDIIN equ 11
        MM_INTERNET_SSW_WAVEOUT equ 12
        MM_INTERNET_SSW_WAVEIN equ 13
        MM_SONY_ACM_SCX equ 1
        MM_UH_ACM_ADPCM equ 1
        MM_SYDEC_NV_WAVEIN equ 1
        MM_SYDEC_NV_WAVEOUT equ 2
        MM_FLEXION_X300_WAVEIN equ 1
        MM_FLEXION_X300_WAVEOUT equ 2
        MM_VIA_WAVEOUT equ 1
        MM_VIA_WAVEIN equ 2
        MM_VIA_MIXER equ 3
        MM_VIA_AUX equ 4
        MM_VIA_MPU401_MIDIOUT equ 5
        MM_VIA_MPU401_MIDIIN equ 6
        MM_VIA_SWFM_SYNTH equ 7
        MM_VIA_WDM_WAVEOUT equ 8
        MM_VIA_WDM_WAVEIN equ 9
        MM_VIA_WDM_MIXER equ 10
        MM_VIA_WDM_MPU401_MIDIOUT equ 11
        MM_VIA_WDM_MPU401_MIDIIN equ 12
        MM_MICRONAS_SC4 equ 1
        MM_MICRONAS_CLP833 equ 2
        MM_HP_WAVEOUT equ 1
        MM_HP_WAVEIN equ 2
        MM_QUICKAUDIO_MINIMIDI equ 1
        MM_QUICKAUDIO_MAXIMIDI equ 2
        MM_ICCC_UNA3_WAVEIN equ 1
        MM_ICCC_UNA3_WAVEOUT equ 2
        MM_ICCC_UNA3_AUX equ 3
        MM_ICCC_UNA3_MIXER equ 4
        MM_3COM_CB_MIXER equ 1
        MM_3COM_CB_WAVEIN equ 2
        MM_3COM_CB_WAVEOUT equ 3
        MM_MINDMAKER_GC_WAVEIN equ 1
        MM_MINDMAKER_GC_WAVEOUT equ 2
        MM_MINDMAKER_GC_MIXER equ 3
        MM_TELEKOL_WAVEOUT equ 1
        MM_TELEKOL_WAVEIN equ 2
        MM_ALGOVISION_VB80WAVEOUT equ 1
        MM_ALGOVISION_VB80WAVEIN equ 2
        MM_ALGOVISION_VB80MIXER equ 3
        MM_ALGOVISION_VB80AUX equ 4
        MM_ALGOVISION_VB80AUX2 equ 5
      endif
      RIFFINFO_IARL equ <mmioFOURCC('I', 'A', 'R', 'L')>
      RIFFINFO_IART equ <mmioFOURCC('I', 'A', 'R', 'T')>
      RIFFINFO_ICMS equ <mmioFOURCC('I', 'C', 'M', 'S')>
      RIFFINFO_ICMT equ <mmioFOURCC('I', 'C', 'M', 'T')>
      RIFFINFO_ICOP equ <mmioFOURCC('I', 'C', 'O', 'P')>
      RIFFINFO_ICRD equ <mmioFOURCC('I', 'C', 'R', 'D')>
      RIFFINFO_ICRP equ <mmioFOURCC('I', 'C', 'R', 'P')>
      RIFFINFO_IDIM equ <mmioFOURCC('I', 'D', 'I', 'M')>
      RIFFINFO_IDPI equ <mmioFOURCC('I', 'D', 'P', 'I')>
      RIFFINFO_IENG equ <mmioFOURCC('I', 'E', 'N', 'G')>
      RIFFINFO_IGNR equ <mmioFOURCC('I', 'G', 'N', 'R')>
      RIFFINFO_IKEY equ <mmioFOURCC('I', 'K', 'E', 'Y')>
      RIFFINFO_ILGT equ <mmioFOURCC('I', 'L', 'G', 'T')>
      RIFFINFO_IMED equ <mmioFOURCC('I', 'M', 'E', 'D')>
      RIFFINFO_INAM equ <mmioFOURCC('I', 'N', 'A', 'M')>
      RIFFINFO_IPLT equ <mmioFOURCC('I', 'P', 'L', 'T')>
      RIFFINFO_IPRD equ <mmioFOURCC('I', 'P', 'R', 'D')>
      RIFFINFO_ISBJ equ <mmioFOURCC('I', 'S', 'B', 'J')>
      RIFFINFO_ISFT equ <mmioFOURCC('I', 'S', 'F', 'T')>
      RIFFINFO_ISHP equ <mmioFOURCC('I', 'S', 'H', 'P')>
      RIFFINFO_ISRC equ <mmioFOURCC('I', 'S', 'R', 'C')>
      RIFFINFO_ISRF equ <mmioFOURCC('I', 'S', 'R', 'F')>
      RIFFINFO_ITCH equ <mmioFOURCC('I', 'T', 'C', 'H')>
      RIFFINFO_ISMP equ <mmioFOURCC('I', 'S', 'M', 'P')>
      RIFFINFO_IDIT equ <mmioFOURCC('I', 'D', 'I', 'T')>
      RIFFINFO_ITRK equ <mmioFOURCC('I', 'T', 'R', 'K')>
      RIFFINFO_ITOC equ <mmioFOURCC('I', 'T', 'O', 'C')>
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_GAMES)
      ifndef NONEWWAVE
        WAVE_FORMAT_UNKNOWN equ 0000h
        WAVE_FORMAT_ADPCM equ 0002h
        WAVE_FORMAT_IEEE_FLOAT equ 0003h
        WAVE_FORMAT_VSELP equ 0004h
        WAVE_FORMAT_IBM_CVSD equ 0005h
        WAVE_FORMAT_ALAW equ 0006h
        WAVE_FORMAT_MULAW equ 0007h
        WAVE_FORMAT_DTS equ 0008h
        WAVE_FORMAT_DRM equ 0009h
        WAVE_FORMAT_WMAVOICE9 equ 000Ah
        WAVE_FORMAT_WMAVOICE10 equ 000Bh
        WAVE_FORMAT_OKI_ADPCM equ 0010h
        WAVE_FORMAT_DVI_ADPCM equ 0011h
        WAVE_FORMAT_IMA_ADPCM equ <(WAVE_FORMAT_DVI_ADPCM)>
        WAVE_FORMAT_MEDIASPACE_ADPCM equ 0012h
        WAVE_FORMAT_SIERRA_ADPCM equ 0013h
        WAVE_FORMAT_G723_ADPCM equ 0014h
        WAVE_FORMAT_DIGISTD equ 0015h
        WAVE_FORMAT_DIGIFIX equ 0016h
        WAVE_FORMAT_DIALOGIC_OKI_ADPCM equ 0017h
        WAVE_FORMAT_MEDIAVISION_ADPCM equ 0018h
        WAVE_FORMAT_CU_CODEC equ 0019h
        WAVE_FORMAT_HP_DYN_VOICE equ 001Ah
        WAVE_FORMAT_YAMAHA_ADPCM equ 0020h
        WAVE_FORMAT_SONARC equ 0021h
        WAVE_FORMAT_DSPGROUP_TRUESPEECH equ 0022h
        WAVE_FORMAT_ECHOSC1 equ 0023h
        WAVE_FORMAT_AUDIOFILE_AF36 equ 0024h
        WAVE_FORMAT_APTX equ 0025h
        WAVE_FORMAT_AUDIOFILE_AF10 equ 0026h
        WAVE_FORMAT_PROSODY_1612 equ 0027h
        WAVE_FORMAT_LRC equ 0028h
        WAVE_FORMAT_DOLBY_AC2 equ 0030h
        WAVE_FORMAT_GSM610 equ 0031h
        WAVE_FORMAT_MSNAUDIO equ 0032h
        WAVE_FORMAT_ANTEX_ADPCME equ 0033h
        WAVE_FORMAT_CONTROL_RES_VQLPC equ 0034h
        WAVE_FORMAT_DIGIREAL equ 0035h
        WAVE_FORMAT_DIGIADPCM equ 0036h
        WAVE_FORMAT_CONTROL_RES_CR10 equ 0037h
        WAVE_FORMAT_NMS_VBXADPCM equ 0038h
        WAVE_FORMAT_CS_IMAADPCM equ 0039h
        WAVE_FORMAT_ECHOSC3 equ 003Ah
        WAVE_FORMAT_ROCKWELL_ADPCM equ 003Bh
        WAVE_FORMAT_ROCKWELL_DIGITALK equ 003Ch
        WAVE_FORMAT_XEBEC equ 003Dh
        WAVE_FORMAT_G721_ADPCM equ 0040h
        WAVE_FORMAT_G728_CELP equ 0041h
        WAVE_FORMAT_MSG723 equ 0042h
        WAVE_FORMAT_INTEL_G723_1 equ 0043h
        WAVE_FORMAT_INTEL_G729 equ 0044h
        WAVE_FORMAT_SHARP_G726 equ 0045h
        WAVE_FORMAT_MPEG equ 0050h
        WAVE_FORMAT_RT24 equ 0052h
        WAVE_FORMAT_PAC equ 0053h
        WAVE_FORMAT_MPEGLAYER3 equ 0055h
        WAVE_FORMAT_LUCENT_G723 equ 0059h
        WAVE_FORMAT_CIRRUS equ 0060h
        WAVE_FORMAT_ESPCM equ 0061h
        WAVE_FORMAT_VOXWARE equ 0062h
        WAVE_FORMAT_CANOPUS_ATRAC equ 0063h
        WAVE_FORMAT_G726_ADPCM equ 0064h
        WAVE_FORMAT_G722_ADPCM equ 0065h
        WAVE_FORMAT_DSAT equ 0066h
        WAVE_FORMAT_DSAT_DISPLAY equ 0067h
        WAVE_FORMAT_VOXWARE_BYTE_ALIGNED equ 0069h
        WAVE_FORMAT_VOXWARE_AC8 equ 0070h
        WAVE_FORMAT_VOXWARE_AC10 equ 0071h
        WAVE_FORMAT_VOXWARE_AC16 equ 0072h
        WAVE_FORMAT_VOXWARE_AC20 equ 0073h
        WAVE_FORMAT_VOXWARE_RT24 equ 0074h
        WAVE_FORMAT_VOXWARE_RT29 equ 0075h
        WAVE_FORMAT_VOXWARE_RT29HW equ 0076h
        WAVE_FORMAT_VOXWARE_VR12 equ 0077h
        WAVE_FORMAT_VOXWARE_VR18 equ 0078h
        WAVE_FORMAT_VOXWARE_TQ40 equ 0079h
        WAVE_FORMAT_VOXWARE_SC3 equ 007Ah
        WAVE_FORMAT_VOXWARE_SC3_1 equ 007Bh
        WAVE_FORMAT_SOFTSOUND equ 0080h
        WAVE_FORMAT_VOXWARE_TQ60 equ 0081h
        WAVE_FORMAT_MSRT24 equ 0082h
        WAVE_FORMAT_G729A equ 0083h
        WAVE_FORMAT_MVI_MVI2 equ 0084h
        WAVE_FORMAT_DF_G726 equ 0085h
        WAVE_FORMAT_DF_GSM610 equ 0086h
        WAVE_FORMAT_ISIAUDIO equ 0088h
        WAVE_FORMAT_ONLIVE equ 0089h
        WAVE_FORMAT_MULTITUDE_FT_SX20 equ 008Ah
        WAVE_FORMAT_INFOCOM_ITS_G721_ADPCM equ 008Bh
        WAVE_FORMAT_CONVEDIA_G729 equ 008Ch
        WAVE_FORMAT_CONGRUENCY equ 008Dh
        WAVE_FORMAT_SBC24 equ 0091h
        WAVE_FORMAT_DOLBY_AC3_SPDIF equ 0092h
        WAVE_FORMAT_MEDIASONIC_G723 equ 0093h
        WAVE_FORMAT_PROSODY_8KBPS equ 0094h
        WAVE_FORMAT_ZYXEL_ADPCM equ 0097h
        WAVE_FORMAT_PHILIPS_LPCBB equ 0098h
        WAVE_FORMAT_PACKED equ 0099h
        WAVE_FORMAT_MALDEN_PHONYTALK equ 00A0h
        WAVE_FORMAT_RACAL_RECORDER_GSM equ 00A1h
        WAVE_FORMAT_RACAL_RECORDER_G720_A equ 00A2h
        WAVE_FORMAT_RACAL_RECORDER_G723_1 equ 00A3h
        WAVE_FORMAT_RACAL_RECORDER_TETRA_ACELP equ 00A4h
        WAVE_FORMAT_NEC_AAC equ 00B0h
        WAVE_FORMAT_RAW_AAC1 equ 00FFh
        WAVE_FORMAT_RHETOREX_ADPCM equ 0100h
        WAVE_FORMAT_IRAT equ 0101h
        WAVE_FORMAT_VIVO_G723 equ 0111h
        WAVE_FORMAT_VIVO_SIREN equ 0112h
        WAVE_FORMAT_PHILIPS_CELP equ 0120h
        WAVE_FORMAT_PHILIPS_GRUNDIG equ 0121h
        WAVE_FORMAT_DIGITAL_G723 equ 0123h
        WAVE_FORMAT_SANYO_LD_ADPCM equ 0125h
        WAVE_FORMAT_SIPROLAB_ACEPLNET equ 0130h
        WAVE_FORMAT_SIPROLAB_ACELP4800 equ 0131h
        WAVE_FORMAT_SIPROLAB_ACELP8V3 equ 0132h
        WAVE_FORMAT_SIPROLAB_G729 equ 0133h
        WAVE_FORMAT_SIPROLAB_G729A equ 0134h
        WAVE_FORMAT_SIPROLAB_KELVIN equ 0135h
        WAVE_FORMAT_VOICEAGE_AMR equ 0136h
        WAVE_FORMAT_G726ADPCM equ 0140h
        WAVE_FORMAT_DICTAPHONE_CELP68 equ 0141h
        WAVE_FORMAT_DICTAPHONE_CELP54 equ 0142h
        WAVE_FORMAT_QUALCOMM_PUREVOICE equ 0150h
        WAVE_FORMAT_QUALCOMM_HALFRATE equ 0151h
        WAVE_FORMAT_TUBGSM equ 0155h
        WAVE_FORMAT_MSAUDIO1 equ 0160h
        WAVE_FORMAT_WMAUDIO2 equ 0161h
        WAVE_FORMAT_WMAUDIO3 equ 0162h
        WAVE_FORMAT_WMAUDIO_LOSSLESS equ 0163h
        WAVE_FORMAT_WMASPDIF equ 0164h
        WAVE_FORMAT_UNISYS_NAP_ADPCM equ 0170h
        WAVE_FORMAT_UNISYS_NAP_ULAW equ 0171h
        WAVE_FORMAT_UNISYS_NAP_ALAW equ 0172h
        WAVE_FORMAT_UNISYS_NAP_16K equ 0173h
        WAVE_FORMAT_SYCOM_ACM_SYC008 equ 0174h
        WAVE_FORMAT_SYCOM_ACM_SYC701_G726L equ 0175h
        WAVE_FORMAT_SYCOM_ACM_SYC701_CELP54 equ 0176h
        WAVE_FORMAT_SYCOM_ACM_SYC701_CELP68 equ 0177h
        WAVE_FORMAT_KNOWLEDGE_ADVENTURE_ADPCM equ 0178h
        WAVE_FORMAT_FRAUNHOFER_IIS_MPEG2_AAC equ 0180h
        WAVE_FORMAT_DTS_DS equ 0190h
        WAVE_FORMAT_CREATIVE_ADPCM equ 0200h
        WAVE_FORMAT_CREATIVE_FASTSPEECH8 equ 0202h
        WAVE_FORMAT_CREATIVE_FASTSPEECH10 equ 0203h
        WAVE_FORMAT_UHER_ADPCM equ 0210h
        WAVE_FORMAT_ULEAD_DV_AUDIO equ 0215h
        WAVE_FORMAT_ULEAD_DV_AUDIO_1 equ 0216h
        WAVE_FORMAT_QUARTERDECK equ 0220h
        WAVE_FORMAT_ILINK_VC equ 0230h
        WAVE_FORMAT_RAW_SPORT equ 0240h
        WAVE_FORMAT_ESST_AC3 equ 0241h
        WAVE_FORMAT_GENERIC_PASSTHRU equ 0249h
        WAVE_FORMAT_IPI_HSX equ 0250h
        WAVE_FORMAT_IPI_RPELP equ 0251h
        WAVE_FORMAT_CS2 equ 0260h
        WAVE_FORMAT_SONY_SCX equ 0270h
        WAVE_FORMAT_SONY_SCY equ 0271h
        WAVE_FORMAT_SONY_ATRAC3 equ 0272h
        WAVE_FORMAT_SONY_SPC equ 0273h
        WAVE_FORMAT_TELUM_AUDIO equ 0280h
        WAVE_FORMAT_TELUM_IA_AUDIO equ 0281h
        WAVE_FORMAT_NORCOM_VOICE_SYSTEMS_ADPCM equ 0285h
        WAVE_FORMAT_FM_TOWNS_SND equ 0300h
        WAVE_FORMAT_MICRONAS equ 0350h
        WAVE_FORMAT_MICRONAS_CELP833 equ 0351h
        WAVE_FORMAT_BTV_DIGITAL equ 0400h
        WAVE_FORMAT_INTEL_MUSIC_CODER equ 0401h
        WAVE_FORMAT_INDEO_AUDIO equ 0402h
        WAVE_FORMAT_QDESIGN_MUSIC equ 0450h
        WAVE_FORMAT_ON2_VP7_AUDIO equ 0500h
        WAVE_FORMAT_ON2_VP6_AUDIO equ 0501h
        WAVE_FORMAT_VME_VMPCM equ 0680h
        WAVE_FORMAT_TPC equ 0681h
        WAVE_FORMAT_LIGHTWAVE_LOSSLESS equ 08AEh
        WAVE_FORMAT_OLIGSM equ 1000h
        WAVE_FORMAT_OLIADPCM equ 1001h
        WAVE_FORMAT_OLICELP equ 1002h
        WAVE_FORMAT_OLISBC equ 1003h
        WAVE_FORMAT_OLIOPR equ 1004h
        WAVE_FORMAT_LH_CODEC equ 1100h
        WAVE_FORMAT_LH_CODEC_CELP equ 1101h
        WAVE_FORMAT_LH_CODEC_SBC8 equ 1102h
        WAVE_FORMAT_LH_CODEC_SBC12 equ 1103h
        WAVE_FORMAT_LH_CODEC_SBC16 equ 1104h
        WAVE_FORMAT_NORRIS equ 1400h
        WAVE_FORMAT_ISIAUDIO_2 equ 1401h
        WAVE_FORMAT_SOUNDSPACE_MUSICOMPRESS equ 1500h
        WAVE_FORMAT_MPEG_ADTS_AAC equ 1600h
        WAVE_FORMAT_MPEG_RAW_AAC equ 1601h
        WAVE_FORMAT_MPEG_LOAS equ 1602h
        WAVE_FORMAT_NOKIA_MPEG_ADTS_AAC equ 1608h
        WAVE_FORMAT_NOKIA_MPEG_RAW_AAC equ 1609h
        WAVE_FORMAT_VODAFONE_MPEG_ADTS_AAC equ 160Ah
        WAVE_FORMAT_VODAFONE_MPEG_RAW_AAC equ 160Bh
        WAVE_FORMAT_MPEG_HEAAC equ 1610h
        WAVE_FORMAT_VOXWARE_RT24_SPEECH equ 181Ch
        WAVE_FORMAT_SONICFOUNDRY_LOSSLESS equ 1971h
        WAVE_FORMAT_INNINGS_TELECOM_ADPCM equ 1979h
        WAVE_FORMAT_LUCENT_SX8300P equ 1C07h
        WAVE_FORMAT_LUCENT_SX5363S equ 1C0Ch
        WAVE_FORMAT_CUSEEME equ 1F03h
        WAVE_FORMAT_NTCSOFT_ALF2CM_ACM equ 1FC4h
        WAVE_FORMAT_DVM equ 2000h
        WAVE_FORMAT_DTS2 equ 2001h
        WAVE_FORMAT_MAKEAVIS equ 3313h
        WAVE_FORMAT_DIVIO_MPEG4_AAC equ 4143h
        WAVE_FORMAT_NOKIA_ADAPTIVE_MULTIRATE equ 4201h
        WAVE_FORMAT_DIVIO_G726 equ 4243h
        WAVE_FORMAT_LEAD_SPEECH equ 434Ch
        WAVE_FORMAT_LEAD_VORBIS equ 564Ch
        WAVE_FORMAT_WAVPACK_AUDIO equ 5756h
        WAVE_FORMAT_ALAC equ 6C61h
        WAVE_FORMAT_OGG_VORBIS_MODE_1 equ 674Fh
        WAVE_FORMAT_OGG_VORBIS_MODE_2 equ 6750h
        WAVE_FORMAT_OGG_VORBIS_MODE_3 equ 6751h
        WAVE_FORMAT_OGG_VORBIS_MODE_1_PLUS equ 676Fh
        WAVE_FORMAT_OGG_VORBIS_MODE_2_PLUS equ 6770h
        WAVE_FORMAT_OGG_VORBIS_MODE_3_PLUS equ 6771h
        WAVE_FORMAT_3COM_NBX equ 7000h
        WAVE_FORMAT_OPUS equ 704Fh
        WAVE_FORMAT_FAAD_AAC equ 706Dh
        WAVE_FORMAT_AMR_NB equ 7361h
        WAVE_FORMAT_AMR_WB equ 7362h
        WAVE_FORMAT_AMR_WP equ 7363h
        WAVE_FORMAT_GSM_AMR_CBR equ 7A21h
        WAVE_FORMAT_GSM_AMR_VBR_SID equ 7A22h
        WAVE_FORMAT_COMVERSE_INFOSYS_G723_1 equ 0A100h
        WAVE_FORMAT_COMVERSE_INFOSYS_AVQSBC equ 0A101h
        WAVE_FORMAT_COMVERSE_INFOSYS_SBC equ 0A102h
        WAVE_FORMAT_SYMBOL_G729_A equ 0A103h
        WAVE_FORMAT_VOICEAGE_AMR_WB equ 0A104h
        WAVE_FORMAT_INGENIENT_G726 equ 0A105h
        WAVE_FORMAT_MPEG4_AAC equ 0A106h
        WAVE_FORMAT_ENCORE_G726 equ 0A107h
        WAVE_FORMAT_ZOLL_ASAO equ 0A108h
        WAVE_FORMAT_SPEEX_VOICE equ 0A109h
        WAVE_FORMAT_VIANIX_MASC equ 0A10Ah
        WAVE_FORMAT_WM9_SPECTRUM_ANALYZER equ 0A10Bh
        WAVE_FORMAT_WMF_SPECTRUM_ANAYZER equ 0A10Ch
        WAVE_FORMAT_GSM_610 equ 0A10Dh
        WAVE_FORMAT_GSM_620 equ 0A10Eh
        WAVE_FORMAT_GSM_660 equ 0A10Fh
        WAVE_FORMAT_GSM_690 equ 0A110h
        WAVE_FORMAT_GSM_ADAPTIVE_MULTIRATE_WB equ 0A111h
        WAVE_FORMAT_POLYCOM_G722 equ 0A112h
        WAVE_FORMAT_POLYCOM_G728 equ 0A113h
        WAVE_FORMAT_POLYCOM_G729_A equ 0A114h
        WAVE_FORMAT_POLYCOM_SIREN equ 0A115h
        WAVE_FORMAT_GLOBAL_IP_ILBC equ 0A116h
        WAVE_FORMAT_RADIOTIME_TIME_SHIFT_RADIO equ 0A117h
        WAVE_FORMAT_NICE_ACA equ 0A118h
        WAVE_FORMAT_NICE_ADPCM equ 0A119h
        WAVE_FORMAT_VOCORD_G721 equ 0A11Ah
        WAVE_FORMAT_VOCORD_G726 equ 0A11Bh
        WAVE_FORMAT_VOCORD_G722_1 equ 0A11Ch
        WAVE_FORMAT_VOCORD_G728 equ 0A11Dh
        WAVE_FORMAT_VOCORD_G729 equ 0A11Eh
        WAVE_FORMAT_VOCORD_G729_A equ 0A11Fh
        WAVE_FORMAT_VOCORD_G723_1 equ 0A120h
        WAVE_FORMAT_VOCORD_LBC equ 0A121h
        WAVE_FORMAT_NICE_G728 equ 0A122h
        WAVE_FORMAT_FRACE_TELECOM_G729 equ 0A123h
        WAVE_FORMAT_CODIAN equ 0A124h
        WAVE_FORMAT_DOLBY_AC4 equ 0AC40h
        WAVE_FORMAT_FLAC equ 0F1ACh
        if  not Defined(WAVE_FORMAT_EXTENSIBLE)
          WAVE_FORMAT_EXTENSIBLE equ 0FFFEh
        endif
        WAVE_FORMAT_DEVELOPMENT equ (0FFFFh)
      endif
      ifndef WAVE_FORMAT_PCM
        WAVEFORMAT struct
          wFormatTag WORD ?
          nChannels WORD ?
          nSamplesPerSec DWORD ?
          nAvgBytesPerSec DWORD ?
          nBlockAlign WORD ?
        WAVEFORMAT ends
        waveformat_tag typedef WAVEFORMAT
        PWAVEFORMAT typedef ptr WAVEFORMAT
        NPWAVEFORMAT typedef ptr WAVEFORMAT
        LPWAVEFORMAT typedef ptr WAVEFORMAT
        PCMWAVEFORMAT struct
          wf WAVEFORMAT <>
          wBitsPerSample WORD ?
        PCMWAVEFORMAT ends
        pcmwaveformat_tag typedef PCMWAVEFORMAT
        PPCMWAVEFORMAT typedef ptr PCMWAVEFORMAT
        NPPCMWAVEFORMAT typedef ptr PCMWAVEFORMAT
        LPPCMWAVEFORMAT typedef ptr PCMWAVEFORMAT
      endif
      ifndef WAVE_FORMAT_PCM
        WAVE_FORMAT_PCM equ 1
      endif
      ifndef _WAVEFORMATEX_
        _WAVEFORMATEX_ equ <>
        WAVEFORMATEX struct
          wFormatTag WORD ?
          nChannels WORD ?
          nSamplesPerSec DWORD ?
          nAvgBytesPerSec DWORD ?
          nBlockAlign WORD ?
          wBitsPerSample WORD ?
          cbSize WORD ?
        WAVEFORMATEX ends
        tWAVEFORMATEX typedef WAVEFORMATEX
        PWAVEFORMATEX typedef ptr WAVEFORMATEX
        NPWAVEFORMATEX typedef ptr WAVEFORMATEX
        LPWAVEFORMATEX typedef ptr WAVEFORMATEX
      endif
      ifdef GUID_DEFINED
        if  not Defined(_NTRTL_)
          if  not Defined(DEFINE_GUIDEX)
            ifndef DEFINE_GUIDEX
              DEFINE_GUIDEX macro name_
                exitm <EXTERN_C const CDECL GUID name_>
              endm
            endif
            ifndef STATICGUIDOF
              STATICGUIDOF macro guid
                exitm <STATIC_ ## guid>
              endm
            endif
          endif
        endif
        if  not Defined(DEFINE_GUIDSTRUCT)
          if Defined(__cplusplus) and _MSC_VER ge 1100
            ;[...]
          else
            DEFINE_GUIDSTRUCT macro g, n
              exitm <DEFINE_GUIDEX(n)>
            endm
            DEFINE_GUIDNAMED macro n
              exitm <n>
            endm
          endif
        endif
        if  not Defined(DEFINE_WAVEFORMATEX_GUID)
          DEFINE_WAVEFORMATEX_GUID macro x
            exitm <(x), 0000h, 0010h, 80h, 00h, 00h, 0aah, 00h, 38h, 9bh, 71h>
          endm
        endif
        if  not Defined(STATIC_KSDATAFORMAT_SUBTYPE_PCM)
          STATIC_KSDATAFORMAT_SUBTYPE_PCM equ <DEFINE_WAVEFORMATEX_GUID(WAVE_FORMAT_PCM)>
          DEFINE_GUIDSTRUCT("00000001-0000-0010-8000-00aa00389b71", KSDATAFORMAT_SUBTYPE_PCM)
          KSDATAFORMAT_SUBTYPE_PCM equ <DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_PCM)>
        endif
        if  not Defined(RC_INVOKED)
          if  not Defined(STATIC_KSDATAFORMAT_SUBTYPE_IEEE_FLOAT)
            STATIC_KSDATAFORMAT_SUBTYPE_IEEE_FLOAT equ <DEFINE_WAVEFORMATEX_GUID(WAVE_FORMAT_IEEE_FLOAT)>
            DEFINE_GUIDSTRUCT("00000003-0000-0010-8000-00aa00389b71", KSDATAFORMAT_SUBTYPE_IEEE_FLOAT)
            KSDATAFORMAT_SUBTYPE_IEEE_FLOAT equ <DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_IEEE_FLOAT)>
          endif
          if  not Defined(STATIC_KSDATAFORMAT_SUBTYPE_WAVEFORMATEX)
            STATIC_KSDATAFORMAT_SUBTYPE_WAVEFORMATEX equ 00000000h, 0000h, 0010h, 80h, 00h, 00h, 0aah, 00h, 38h, 9bh, 71h
            DEFINE_GUIDSTRUCT("00000000-0000-0010-8000-00aa00389b71", KSDATAFORMAT_SUBTYPE_WAVEFORMATEX)
            KSDATAFORMAT_SUBTYPE_WAVEFORMATEX equ <DEFINE_GUIDNAMED(KSDATAFORMAT_SUBTYPE_WAVEFORMATEX)>
          endif
        endif
        if  not Defined(INIT_WAVEFORMATEX_GUID)
          INIT_WAVEFORMATEX_GUID macro Guid, x
            exitm <{ * (Guid) = KSDATAFORMAT_SUBTYPE_WAVEFORMATEX ; (Guid) - Data1 = (x) ; }>
          endm
        endif
        if  not Defined(EXTRACT_WAVEFORMATEX_ID)
          EXTRACT_WAVEFORMATEX_ID macro Guid
            exitm <((Guid) - Data1)>
          endm
        endif
        if  not Defined(IS_VALID_WAVEFORMATEX_GUID)
          IS_VALID_WAVEFORMATEX_GUID macro Guid
            exitm <(! memcmp (((PUSHORT) and KSDATAFORMAT_SUBTYPE_WAVEFORMATEX) + 1, ((PUSHORT) (Guid)) + 1, sizeof(GUID) - sizeof(USHORT)))>
          endm
        endif
        ifndef _WAVEFORMATEXTENSIBLE_
          _WAVEFORMATEXTENSIBLE_ equ <>
          WAVEFORMATEXTENSIBLE struct
            Format WAVEFORMATEX <>
            union Samples
              wValidBitsPerSample WORD ?
              wSamplesPerBlock WORD ?
              wReserved WORD ?
            ends
            dwChannelMask DWORD ?
            SubFormat GUID <>
          WAVEFORMATEXTENSIBLE ends
          PWAVEFORMATEXTENSIBLE typedef ptr WAVEFORMATEXTENSIBLE
        endif
        WAVEFORMATPCMEX typedef WAVEFORMATEXTENSIBLE
        PWAVEFORMATPCMEX typedef ptr WAVEFORMATPCMEX
        NPWAVEFORMATPCMEX typedef ptr WAVEFORMATPCMEX
        LPWAVEFORMATPCMEX typedef ptr WAVEFORMATPCMEX
        WAVEFORMATIEEEFLOATEX typedef WAVEFORMATEXTENSIBLE
        PWAVEFORMATIEEEFLOATEX typedef ptr WAVEFORMATIEEEFLOATEX
        NPWAVEFORMATIEEEFLOATEX typedef ptr WAVEFORMATIEEEFLOATEX
        LPWAVEFORMATIEEEFLOATEX typedef ptr WAVEFORMATIEEEFLOATEX
      endif
      ifndef _SPEAKER_POSITIONS_
        _SPEAKER_POSITIONS_ equ <>
        SPEAKER_FRONT_LEFT equ 1h
        SPEAKER_FRONT_RIGHT equ 2h
        SPEAKER_FRONT_CENTER equ 4h
        SPEAKER_LOW_FREQUENCY equ 8h
        SPEAKER_BACK_LEFT equ 10h
        SPEAKER_BACK_RIGHT equ 20h
        SPEAKER_FRONT_LEFT_OF_CENTER equ 40h
        SPEAKER_FRONT_RIGHT_OF_CENTER equ 80h
        SPEAKER_BACK_CENTER equ 100h
        SPEAKER_SIDE_LEFT equ 200h
        SPEAKER_SIDE_RIGHT equ 400h
        SPEAKER_TOP_CENTER equ 800h
        SPEAKER_TOP_FRONT_LEFT equ 1000h
        SPEAKER_TOP_FRONT_CENTER equ 2000h
        SPEAKER_TOP_FRONT_RIGHT equ 4000h
        SPEAKER_TOP_BACK_LEFT equ 8000h
        SPEAKER_TOP_BACK_CENTER equ 10000h
        SPEAKER_TOP_BACK_RIGHT equ 20000h
        SPEAKER_RESERVED equ 7FFC0000h
        SPEAKER_ALL equ 80000000h
      endif
    endif
    ifndef NONEWWAVE
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_GAMES)
        ADPCMCOEFSET struct
          iCoef1 SWORD ?
          iCoef2 SWORD ?
        ADPCMCOEFSET ends
        adpcmcoef_tag typedef ADPCMCOEFSET
        PADPCMCOEFSET typedef ptr ADPCMCOEFSET
        NPADPCMCOEFSET typedef ptr ADPCMCOEFSET
        LPADPCMCOEFSET typedef ptr ADPCMCOEFSET
        ifdef _MSC_VER
        endif
        ADPCMWAVEFORMAT struct
          wfx WAVEFORMATEX <>
          wSamplesPerBlock WORD ?
          wNumCoef WORD ?
          if Defined(_MSC_VER)
            aCoef ADPCMCOEFSET 0 dup (<>)
          else
            aCoef ADPCMCOEFSET 1 dup (<>)
          endif
        ADPCMWAVEFORMAT ends
        adpcmwaveformat_tag typedef ADPCMWAVEFORMAT
        PADPCMWAVEFORMAT typedef ptr ADPCMWAVEFORMAT
        NPADPCMWAVEFORMAT typedef ptr ADPCMWAVEFORMAT
        LPADPCMWAVEFORMAT typedef ptr ADPCMWAVEFORMAT
        ifdef _MSC_VER
        endif
        DRMWAVEFORMAT struct
          wfx WAVEFORMATEX <>
          wReserved WORD ?
          ulContentId ULONG ?
          wfxSecure WAVEFORMATEX <>
        DRMWAVEFORMAT ends
        drmwaveformat_tag typedef DRMWAVEFORMAT
        PDRMWAVEFORMAT typedef ptr DRMWAVEFORMAT
        NPDRMWAVEFORMAT typedef ptr DRMWAVEFORMAT
        LPDRMWAVEFORMAT typedef ptr DRMWAVEFORMAT
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        DVIADPCMWAVEFORMAT struct
          wfx WAVEFORMATEX <>
          wSamplesPerBlock WORD ?
        DVIADPCMWAVEFORMAT ends
        dvi_adpcmwaveformat_tag typedef DVIADPCMWAVEFORMAT
        PDVIADPCMWAVEFORMAT typedef ptr DVIADPCMWAVEFORMAT
        NPDVIADPCMWAVEFORMAT typedef ptr DVIADPCMWAVEFORMAT
        LPDVIADPCMWAVEFORMAT typedef ptr DVIADPCMWAVEFORMAT
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_GAMES)
        IMAADPCMWAVEFORMAT struct
          wfx WAVEFORMATEX <>
          wSamplesPerBlock WORD ?
        IMAADPCMWAVEFORMAT ends
        ima_adpcmwaveformat_tag typedef IMAADPCMWAVEFORMAT
        PIMAADPCMWAVEFORMAT typedef ptr IMAADPCMWAVEFORMAT
        NPIMAADPCMWAVEFORMAT typedef ptr IMAADPCMWAVEFORMAT
        LPIMAADPCMWAVEFORMAT typedef ptr IMAADPCMWAVEFORMAT
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        MEDIASPACEADPCMWAVEFORMAT struct
          wfx WAVEFORMATEX <>
          wRevision WORD ?
        MEDIASPACEADPCMWAVEFORMAT ends
        mediaspace_adpcmwaveformat_tag typedef MEDIASPACEADPCMWAVEFORMAT
        PMEDIASPACEADPCMWAVEFORMAT typedef ptr MEDIASPACEADPCMWAVEFORMAT
        NPMEDIASPACEADPCMWAVEFORMAT typedef ptr MEDIASPACEADPCMWAVEFORMAT
        LPMEDIASPACEADPCMWAVEFORMAT typedef ptr MEDIASPACEADPCMWAVEFORMAT
        SIERRAADPCMWAVEFORMAT struct
          wfx WAVEFORMATEX <>
          wRevision WORD ?
        SIERRAADPCMWAVEFORMAT ends
        sierra_adpcmwaveformat_tag typedef SIERRAADPCMWAVEFORMAT
        PSIERRAADPCMWAVEFORMAT typedef ptr SIERRAADPCMWAVEFORMAT
        NPSIERRAADPCMWAVEFORMAT typedef ptr SIERRAADPCMWAVEFORMAT
        LPSIERRAADPCMWAVEFORMAT typedef ptr SIERRAADPCMWAVEFORMAT
        G723_ADPCMWAVEFORMAT struct
          wfx WAVEFORMATEX <>
          cbExtraSize WORD ?
          nAuxBlockSize WORD ?
        G723_ADPCMWAVEFORMAT ends
        g723_adpcmwaveformat_tag typedef G723_ADPCMWAVEFORMAT
        PG723_ADPCMWAVEFORMAT typedef ptr G723_ADPCMWAVEFORMAT
        NPG723_ADPCMWAVEFORMAT typedef ptr G723_ADPCMWAVEFORMAT
        LPG723_ADPCMWAVEFORMAT typedef ptr G723_ADPCMWAVEFORMAT
        DIGISTDWAVEFORMAT struct
          wfx WAVEFORMATEX <>
        DIGISTDWAVEFORMAT ends
        digistdwaveformat_tag typedef DIGISTDWAVEFORMAT
        PDIGISTDWAVEFORMAT typedef ptr DIGISTDWAVEFORMAT
        NPDIGISTDWAVEFORMAT typedef ptr DIGISTDWAVEFORMAT
        LPDIGISTDWAVEFORMAT typedef ptr DIGISTDWAVEFORMAT
        DIGIFIXWAVEFORMAT struct
          wfx WAVEFORMATEX <>
        DIGIFIXWAVEFORMAT ends
        digifixwaveformat_tag typedef DIGIFIXWAVEFORMAT
        PDIGIFIXWAVEFORMAT typedef ptr DIGIFIXWAVEFORMAT
        NPDIGIFIXWAVEFORMAT typedef ptr DIGIFIXWAVEFORMAT
        LPDIGIFIXWAVEFORMAT typedef ptr DIGIFIXWAVEFORMAT
        DIALOGICOKIADPCMWAVEFORMAT struct
          ewf WAVEFORMATEX <>
        DIALOGICOKIADPCMWAVEFORMAT ends
        creative_fastspeechformat_tag typedef DIALOGICOKIADPCMWAVEFORMAT
        PDIALOGICOKIADPCMWAVEFORMAT typedef ptr DIALOGICOKIADPCMWAVEFORMAT
        NPDIALOGICOKIADPCMWAVEFORMAT typedef ptr DIALOGICOKIADPCMWAVEFORMAT
        LPDIALOGICOKIADPCMWAVEFORMAT typedef ptr DIALOGICOKIADPCMWAVEFORMAT
        YAMAHA_ADPCMWAVEFORMAT struct
          wfx WAVEFORMATEX <>
        YAMAHA_ADPCMWAVEFORMAT ends
        yamaha_adpmcwaveformat_tag typedef YAMAHA_ADPCMWAVEFORMAT
        PYAMAHA_ADPCMWAVEFORMAT typedef ptr YAMAHA_ADPCMWAVEFORMAT
        NPYAMAHA_ADPCMWAVEFORMAT typedef ptr YAMAHA_ADPCMWAVEFORMAT
        LPYAMAHA_ADPCMWAVEFORMAT typedef ptr YAMAHA_ADPCMWAVEFORMAT
        SONARCWAVEFORMAT struct
          wfx WAVEFORMATEX <>
          wCompType WORD ?
        SONARCWAVEFORMAT ends
        sonarcwaveformat_tag typedef SONARCWAVEFORMAT
        PSONARCWAVEFORMAT typedef ptr SONARCWAVEFORMAT
        NPSONARCWAVEFORMAT typedef ptr SONARCWAVEFORMAT
        LPSONARCWAVEFORMAT typedef ptr SONARCWAVEFORMAT
        TRUESPEECHWAVEFORMAT struct
          wfx WAVEFORMATEX <>
          wRevision WORD ?
          nSamplesPerBlock WORD ?
          abReserved BYTE 28 dup (?)
        TRUESPEECHWAVEFORMAT ends
        truespeechwaveformat_tag typedef TRUESPEECHWAVEFORMAT
        PTRUESPEECHWAVEFORMAT typedef ptr TRUESPEECHWAVEFORMAT
        NPTRUESPEECHWAVEFORMAT typedef ptr TRUESPEECHWAVEFORMAT
        LPTRUESPEECHWAVEFORMAT typedef ptr TRUESPEECHWAVEFORMAT
        ECHOSC1WAVEFORMAT struct
          wfx WAVEFORMATEX <>
        ECHOSC1WAVEFORMAT ends
        echosc1waveformat_tag typedef ECHOSC1WAVEFORMAT
        PECHOSC1WAVEFORMAT typedef ptr ECHOSC1WAVEFORMAT
        NPECHOSC1WAVEFORMAT typedef ptr ECHOSC1WAVEFORMAT
        LPECHOSC1WAVEFORMAT typedef ptr ECHOSC1WAVEFORMAT
        AUDIOFILE_AF36WAVEFORMAT struct
          wfx WAVEFORMATEX <>
        AUDIOFILE_AF36WAVEFORMAT ends
        audiofile_af36waveformat_tag typedef AUDIOFILE_AF36WAVEFORMAT
        PAUDIOFILE_AF36WAVEFORMAT typedef ptr AUDIOFILE_AF36WAVEFORMAT
        NPAUDIOFILE_AF36WAVEFORMAT typedef ptr AUDIOFILE_AF36WAVEFORMAT
        LPAUDIOFILE_AF36WAVEFORMAT typedef ptr AUDIOFILE_AF36WAVEFORMAT
        APTXWAVEFORMAT struct
          wfx WAVEFORMATEX <>
        APTXWAVEFORMAT ends
        aptxwaveformat_tag typedef APTXWAVEFORMAT
        PAPTXWAVEFORMAT typedef ptr APTXWAVEFORMAT
        NPAPTXWAVEFORMAT typedef ptr APTXWAVEFORMAT
        LPAPTXWAVEFORMAT typedef ptr APTXWAVEFORMAT
        AUDIOFILE_AF10WAVEFORMAT struct
          wfx WAVEFORMATEX <>
        AUDIOFILE_AF10WAVEFORMAT ends
        audiofile_af10waveformat_tag typedef AUDIOFILE_AF10WAVEFORMAT
        PAUDIOFILE_AF10WAVEFORMAT typedef ptr AUDIOFILE_AF10WAVEFORMAT
        NPAUDIOFILE_AF10WAVEFORMAT typedef ptr AUDIOFILE_AF10WAVEFORMAT
        LPAUDIOFILE_AF10WAVEFORMAT typedef ptr AUDIOFILE_AF10WAVEFORMAT
        DOLBYAC2WAVEFORMAT struct
          wfx WAVEFORMATEX <>
          nAuxBitsCode WORD ?
        DOLBYAC2WAVEFORMAT ends
        dolbyac2waveformat_tag typedef DOLBYAC2WAVEFORMAT
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_GAMES)
        GSM610WAVEFORMAT struct
          wfx WAVEFORMATEX <>
          wSamplesPerBlock WORD ?
        GSM610WAVEFORMAT ends
        gsm610waveformat_tag typedef GSM610WAVEFORMAT
        PGSM610WAVEFORMAT typedef ptr GSM610WAVEFORMAT
        NPGSM610WAVEFORMAT typedef ptr GSM610WAVEFORMAT
        LPGSM610WAVEFORMAT typedef ptr GSM610WAVEFORMAT
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        ADPCMEWAVEFORMAT struct
          wfx WAVEFORMATEX <>
          wSamplesPerBlock WORD ?
        ADPCMEWAVEFORMAT ends
        adpcmewaveformat_tag typedef ADPCMEWAVEFORMAT
        PADPCMEWAVEFORMAT typedef ptr ADPCMEWAVEFORMAT
        NPADPCMEWAVEFORMAT typedef ptr ADPCMEWAVEFORMAT
        LPADPCMEWAVEFORMAT typedef ptr ADPCMEWAVEFORMAT
        CONTRESVQLPCWAVEFORMAT struct
          wfx WAVEFORMATEX <>
          wSamplesPerBlock WORD ?
        CONTRESVQLPCWAVEFORMAT ends
        contres_vqlpcwaveformat_tag typedef CONTRESVQLPCWAVEFORMAT
        PCONTRESVQLPCWAVEFORMAT typedef ptr CONTRESVQLPCWAVEFORMAT
        NPCONTRESVQLPCWAVEFORMAT typedef ptr CONTRESVQLPCWAVEFORMAT
        LPCONTRESVQLPCWAVEFORMAT typedef ptr CONTRESVQLPCWAVEFORMAT
        DIGIREALWAVEFORMAT struct
          wfx WAVEFORMATEX <>
          wSamplesPerBlock WORD ?
        DIGIREALWAVEFORMAT ends
        digirealwaveformat_tag typedef DIGIREALWAVEFORMAT
        PDIGIREALWAVEFORMAT typedef ptr DIGIREALWAVEFORMAT
        NPDIGIREALWAVEFORMAT typedef ptr DIGIREALWAVEFORMAT
        LPDIGIREALWAVEFORMAT typedef ptr DIGIREALWAVEFORMAT
        DIGIADPCMWAVEFORMAT struct
          wfx WAVEFORMATEX <>
          wSamplesPerBlock WORD ?
        DIGIADPCMWAVEFORMAT ends
        digiadpcmmwaveformat_tag typedef DIGIADPCMWAVEFORMAT
        PDIGIADPCMWAVEFORMAT typedef ptr DIGIADPCMWAVEFORMAT
        NPDIGIADPCMWAVEFORMAT typedef ptr DIGIADPCMWAVEFORMAT
        LPDIGIADPCMWAVEFORMAT typedef ptr DIGIADPCMWAVEFORMAT
        CONTRESCR10WAVEFORMAT struct
          wfx WAVEFORMATEX <>
          wSamplesPerBlock WORD ?
        CONTRESCR10WAVEFORMAT ends
        contres_cr10waveformat_tag typedef CONTRESCR10WAVEFORMAT
        PCONTRESCR10WAVEFORMAT typedef ptr CONTRESCR10WAVEFORMAT
        NPCONTRESCR10WAVEFORMAT typedef ptr CONTRESCR10WAVEFORMAT
        LPCONTRESCR10WAVEFORMAT typedef ptr CONTRESCR10WAVEFORMAT
        NMS_VBXADPCMWAVEFORMAT struct
          wfx WAVEFORMATEX <>
          wSamplesPerBlock WORD ?
        NMS_VBXADPCMWAVEFORMAT ends
        nms_vbxadpcmmwaveformat_tag typedef NMS_VBXADPCMWAVEFORMAT
        PNMS_VBXADPCMWAVEFORMAT typedef ptr NMS_VBXADPCMWAVEFORMAT
        NPNMS_VBXADPCMWAVEFORMAT typedef ptr NMS_VBXADPCMWAVEFORMAT
        LPNMS_VBXADPCMWAVEFORMAT typedef ptr NMS_VBXADPCMWAVEFORMAT
        G721_ADPCMWAVEFORMAT struct
          wfx WAVEFORMATEX <>
          nAuxBlockSize WORD ?
        G721_ADPCMWAVEFORMAT ends
        g721_adpcmwaveformat_tag typedef G721_ADPCMWAVEFORMAT
        PG721_ADPCMWAVEFORMAT typedef ptr G721_ADPCMWAVEFORMAT
        NPG721_ADPCMWAVEFORMAT typedef ptr G721_ADPCMWAVEFORMAT
        LPG721_ADPCMWAVEFORMAT typedef ptr G721_ADPCMWAVEFORMAT
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_GAMES)
        MPEG1WAVEFORMAT struct
          wfx WAVEFORMATEX <>
          fwHeadLayer WORD ?
          dwHeadBitrate DWORD ?
          fwHeadMode WORD ?
          fwHeadModeExt WORD ?
          wHeadEmphasis WORD ?
          fwHeadFlags WORD ?
          dwPTSLow DWORD ?
          dwPTSHigh DWORD ?
        MPEG1WAVEFORMAT ends
        mpeg1waveformat_tag typedef MPEG1WAVEFORMAT
        PMPEG1WAVEFORMAT typedef ptr MPEG1WAVEFORMAT
        NPMPEG1WAVEFORMAT typedef ptr MPEG1WAVEFORMAT
        LPMPEG1WAVEFORMAT typedef ptr MPEG1WAVEFORMAT
        ACM_MPEG_LAYER1 equ (0001h)
        ACM_MPEG_LAYER2 equ (0002h)
        ACM_MPEG_LAYER3 equ (0004h)
        ACM_MPEG_STEREO equ (0001h)
        ACM_MPEG_JOINTSTEREO equ (0002h)
        ACM_MPEG_DUALCHANNEL equ (0004h)
        ACM_MPEG_SINGLECHANNEL equ (0008h)
        ACM_MPEG_PRIVATEBIT equ (0001h)
        ACM_MPEG_COPYRIGHT equ (0002h)
        ACM_MPEG_ORIGINALHOME equ (0004h)
        ACM_MPEG_PROTECTIONBIT equ (0008h)
        ACM_MPEG_ID_MPEG1 equ (0010h)
        MPEGLAYER3_WFX_EXTRA_BYTES equ 12
        MPEGLAYER3WAVEFORMAT struct
          wfx WAVEFORMATEX <>
          wID WORD ?
          fdwFlags DWORD ?
          nBlockSize WORD ?
          nFramesPerBlock WORD ?
          nCodecDelay WORD ?
        MPEGLAYER3WAVEFORMAT ends
        mpeglayer3waveformat_tag typedef MPEGLAYER3WAVEFORMAT
        PMPEGLAYER3WAVEFORMAT typedef ptr MPEGLAYER3WAVEFORMAT
        NPMPEGLAYER3WAVEFORMAT typedef ptr MPEGLAYER3WAVEFORMAT
        LPMPEGLAYER3WAVEFORMAT typedef ptr MPEGLAYER3WAVEFORMAT
        MPEGLAYER3_ID_UNKNOWN equ 0
        MPEGLAYER3_ID_MPEG equ 1
        MPEGLAYER3_ID_CONSTANTFRAMESIZE equ 2
        MPEGLAYER3_FLAG_PADDING_ISO equ 00000000h
        MPEGLAYER3_FLAG_PADDING_ON equ 00000001h
        MPEGLAYER3_FLAG_PADDING_OFF equ 00000002h
        HEAACWAVEINFO struct
          wfx WAVEFORMATEX <>
          wPayloadType WORD ?
          wAudioProfileLevelIndication WORD ?
          wStructType WORD ?
          wReserved1 WORD ?
          dwReserved2 DWORD ?
        HEAACWAVEINFO ends
        heaacwaveinfo_tag typedef HEAACWAVEINFO
        PHEAACWAVEINFO typedef ptr HEAACWAVEINFO
        NPHEAACWAVEINFO typedef ptr HEAACWAVEINFO
        LPHEAACWAVEINFO typedef ptr HEAACWAVEINFO
        HEAACWAVEFORMAT struct
          wfInfo HEAACWAVEINFO <>
          pbAudioSpecificConfig BYTE 1 dup (?)
        HEAACWAVEFORMAT ends
        heaacwaveformat_tag typedef HEAACWAVEFORMAT
        PHEAACWAVEFORMAT typedef ptr HEAACWAVEFORMAT
        NPHEAACWAVEFORMAT typedef ptr HEAACWAVEFORMAT
        LPHEAACWAVEFORMAT typedef ptr HEAACWAVEFORMAT
        MM_MSFT_ACM_WMAUDIO equ 39
        WMAUDIO_BITS_PER_SAMPLE equ 16
        WMAUDIO_MAX_CHANNELS equ 2
        MM_MSFT_ACM_MSAUDIO1 equ 39
        MSAUDIO1WAVEFORMAT struct
          wfx WAVEFORMATEX <>
          wSamplesPerBlock WORD ?
          wEncodeOptions WORD ?
        MSAUDIO1WAVEFORMAT ends
        msaudio1waveformat_tag typedef MSAUDIO1WAVEFORMAT
        LPMSAUDIO1WAVEFORMAT typedef ptr MSAUDIO1WAVEFORMAT
        MSAUDIO1_BITS_PER_SAMPLE equ <WMAUDIO_BITS_PER_SAMPLE>
        MSAUDIO1_MAX_CHANNELS equ <WMAUDIO_MAX_CHANNELS>
        MSAUDIO1_WFX_EXTRA_BYTES equ <(sizeof(MSAUDIO1WAVEFORMAT) - sizeof(WAVEFORMATEX))>
        MM_MSFT_ACM_WMAUDIO2 equ 101
        WMAUDIO2WAVEFORMAT struct
          wfx WAVEFORMATEX <>
          dwSamplesPerBlock DWORD ?
          wEncodeOptions WORD ?
          dwSuperBlockAlign DWORD ?
        WMAUDIO2WAVEFORMAT ends
        wmaudio2waveformat_tag typedef WMAUDIO2WAVEFORMAT
        LPWMAUDIO2WAVEFORMAT typedef ptr WMAUDIO2WAVEFORMAT
        WMAUDIO2_BITS_PER_SAMPLE equ <WMAUDIO_BITS_PER_SAMPLE>
        WMAUDIO2_MAX_CHANNELS equ <WMAUDIO_MAX_CHANNELS>
        WMAUDIO2_WFX_EXTRA_BYTES equ <(sizeof(WMAUDIO2WAVEFORMAT) - sizeof(WAVEFORMATEX))>
        WMAUDIO3WAVEFORMAT struct
          wfx WAVEFORMATEX <>
          wValidBitsPerSample WORD ?
          dwChannelMask DWORD ?
          dwReserved1 DWORD ?
          dwReserved2 DWORD ?
          wEncodeOptions WORD ?
          wReserved3 WORD ?
        WMAUDIO3WAVEFORMAT ends
        wmaudio3waveformat_tag typedef WMAUDIO3WAVEFORMAT
        LPWMAUDIO3WAVEFORMAT typedef ptr WMAUDIO3WAVEFORMAT
        WMAUDIO3_WFX_EXTRA_BYTES equ <(sizeof(WMAUDIO3WAVEFORMAT) - sizeof(WAVEFORMATEX))>
      endif
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        CREATIVEADPCMWAVEFORMAT struct
          wfx WAVEFORMATEX <>
          wRevision WORD ?
        CREATIVEADPCMWAVEFORMAT ends
        creative_adpcmwaveformat_tag typedef CREATIVEADPCMWAVEFORMAT
        PCREATIVEADPCMWAVEFORMAT typedef ptr CREATIVEADPCMWAVEFORMAT
        NPCREATIVEADPCMWAVEFORMAT typedef ptr CREATIVEADPCMWAVEFORMAT
        LPCREATIVEADPCMWAVEFORMAT typedef ptr CREATIVEADPCMWAVEFORMAT
        CREATIVEFASTSPEECH8WAVEFORMAT struct
          wfx WAVEFORMATEX <>
          wRevision WORD ?
        CREATIVEFASTSPEECH8WAVEFORMAT ends
        creative_fastspeech8format_tag typedef CREATIVEFASTSPEECH8WAVEFORMAT
        PCREATIVEFASTSPEECH8WAVEFORMAT typedef ptr CREATIVEFASTSPEECH8WAVEFORMAT
        NPCREATIVEFASTSPEECH8WAVEFORMAT typedef ptr CREATIVEFASTSPEECH8WAVEFORMAT
        LPCREATIVEFASTSPEECH8WAVEFORMAT typedef ptr CREATIVEFASTSPEECH8WAVEFORMAT
        CREATIVEFASTSPEECH10WAVEFORMAT struct
          wfx WAVEFORMATEX <>
          wRevision WORD ?
        CREATIVEFASTSPEECH10WAVEFORMAT ends
        creative_fastspeech10format_tag typedef CREATIVEFASTSPEECH10WAVEFORMAT
        PCREATIVEFASTSPEECH10WAVEFORMAT typedef ptr CREATIVEFASTSPEECH10WAVEFORMAT
        NPCREATIVEFASTSPEECH10WAVEFORMAT typedef ptr CREATIVEFASTSPEECH10WAVEFORMAT
        LPCREATIVEFASTSPEECH10WAVEFORMAT typedef ptr CREATIVEFASTSPEECH10WAVEFORMAT
        FMTOWNS_SND_WAVEFORMAT struct
          wfx WAVEFORMATEX <>
          wRevision WORD ?
        FMTOWNS_SND_WAVEFORMAT ends
        fmtowns_snd_waveformat_tag typedef FMTOWNS_SND_WAVEFORMAT
        PFMTOWNS_SND_WAVEFORMAT typedef ptr FMTOWNS_SND_WAVEFORMAT
        NPFMTOWNS_SND_WAVEFORMAT typedef ptr FMTOWNS_SND_WAVEFORMAT
        LPFMTOWNS_SND_WAVEFORMAT typedef ptr FMTOWNS_SND_WAVEFORMAT
        OLIGSMWAVEFORMAT struct
          wfx WAVEFORMATEX <>
        OLIGSMWAVEFORMAT ends
        oligsmwaveformat_tag typedef OLIGSMWAVEFORMAT
        POLIGSMWAVEFORMAT typedef ptr OLIGSMWAVEFORMAT
        NPOLIGSMWAVEFORMAT typedef ptr OLIGSMWAVEFORMAT
        LPOLIGSMWAVEFORMAT typedef ptr OLIGSMWAVEFORMAT
        OLIADPCMWAVEFORMAT struct
          wfx WAVEFORMATEX <>
        OLIADPCMWAVEFORMAT ends
        oliadpcmwaveformat_tag typedef OLIADPCMWAVEFORMAT
        POLIADPCMWAVEFORMAT typedef ptr OLIADPCMWAVEFORMAT
        NPOLIADPCMWAVEFORMAT typedef ptr OLIADPCMWAVEFORMAT
        LPOLIADPCMWAVEFORMAT typedef ptr OLIADPCMWAVEFORMAT
        OLICELPWAVEFORMAT struct
          wfx WAVEFORMATEX <>
        OLICELPWAVEFORMAT ends
        olicelpwaveformat_tag typedef OLICELPWAVEFORMAT
        POLICELPWAVEFORMAT typedef ptr OLICELPWAVEFORMAT
        NPOLICELPWAVEFORMAT typedef ptr OLICELPWAVEFORMAT
        LPOLICELPWAVEFORMAT typedef ptr OLICELPWAVEFORMAT
        OLISBCWAVEFORMAT struct
          wfx WAVEFORMATEX <>
        OLISBCWAVEFORMAT ends
        olisbcwaveformat_tag typedef OLISBCWAVEFORMAT
        POLISBCWAVEFORMAT typedef ptr OLISBCWAVEFORMAT
        NPOLISBCWAVEFORMAT typedef ptr OLISBCWAVEFORMAT
        LPOLISBCWAVEFORMAT typedef ptr OLISBCWAVEFORMAT
        OLIOPRWAVEFORMAT struct
          wfx WAVEFORMATEX <>
        OLIOPRWAVEFORMAT ends
        olioprwaveformat_tag typedef OLIOPRWAVEFORMAT
        POLIOPRWAVEFORMAT typedef ptr OLIOPRWAVEFORMAT
        NPOLIOPRWAVEFORMAT typedef ptr OLIOPRWAVEFORMAT
        LPOLIOPRWAVEFORMAT typedef ptr OLIOPRWAVEFORMAT
        CSIMAADPCMWAVEFORMAT struct
          wfx WAVEFORMATEX <>
        CSIMAADPCMWAVEFORMAT ends
        csimaadpcmwaveformat_tag typedef CSIMAADPCMWAVEFORMAT
        PCSIMAADPCMWAVEFORMAT typedef ptr CSIMAADPCMWAVEFORMAT
        NPCSIMAADPCMWAVEFORMAT typedef ptr CSIMAADPCMWAVEFORMAT
        LPCSIMAADPCMWAVEFORMAT typedef ptr CSIMAADPCMWAVEFORMAT
        ifndef _ACM_WAVEFILTER
          _ACM_WAVEFILTER equ <>
          WAVE_FILTER_UNKNOWN equ 0000h
          WAVE_FILTER_DEVELOPMENT equ (0FFFFh)
          WAVEFILTER struct
            cbStruct DWORD ?
            dwFilterTag DWORD ?
            fdwFilter DWORD ?
            dwReserved DWORD 5 dup (?)
          WAVEFILTER ends
          wavefilter_tag typedef WAVEFILTER
          PWAVEFILTER typedef ptr WAVEFILTER
          NPWAVEFILTER typedef ptr WAVEFILTER
          LPWAVEFILTER typedef ptr WAVEFILTER
        endif
        ifndef WAVE_FILTER_VOLUME
          WAVE_FILTER_VOLUME equ 0001h
          VOLUMEWAVEFILTER struct
            wfltr WAVEFILTER <>
            dwVolume DWORD ?
          VOLUMEWAVEFILTER ends
          wavefilter_volume_tag typedef VOLUMEWAVEFILTER
          PVOLUMEWAVEFILTER typedef ptr VOLUMEWAVEFILTER
          NPVOLUMEWAVEFILTER typedef ptr VOLUMEWAVEFILTER
          LPVOLUMEWAVEFILTER typedef ptr VOLUMEWAVEFILTER
        endif
        ifndef WAVE_FILTER_ECHO
          WAVE_FILTER_ECHO equ 0002h
          ECHOWAVEFILTER struct
            wfltr WAVEFILTER <>
            dwVolume DWORD ?
            dwDelay DWORD ?
          ECHOWAVEFILTER ends
          wavefilter_echo_tag typedef ECHOWAVEFILTER
          PECHOWAVEFILTER typedef ptr ECHOWAVEFILTER
          NPECHOWAVEFILTER typedef ptr ECHOWAVEFILTER
          LPECHOWAVEFILTER typedef ptr ECHOWAVEFILTER
        endif
        RIFFWAVE_inst equ <mmioFOURCC('i', 'n', 's', 't')>
        tag_s_RIFFWAVE_inst struct
          bUnshiftedNote BYTE ?
          chFineTune SBYTE ?
          chGain SBYTE ?
          bLowNote BYTE ?
          bHighNote BYTE ?
          bLowVelocity BYTE ?
          bHighVelocity BYTE ?
        tag_s_RIFFWAVE_inst ends
        s_RIFFWAVE_inst typedef tag_s_RIFFWAVE_INST
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ifndef NONEWRIFF
        RIFFCPPO equ <mmioFOURCC('C', 'P', 'P', 'O')>
        RIFFCPPO_objr equ <mmioFOURCC('o', 'b', 'j', 'r')>
        RIFFCPPO_obji equ <mmioFOURCC('o', 'b', 'j', 'i')>
        RIFFCPPO_clsr equ <mmioFOURCC('c', 'l', 's', 'r')>
        RIFFCPPO_clsi equ <mmioFOURCC('c', 'l', 's', 'i')>
        RIFFCPPO_mbr equ <mmioFOURCC('m', 'b', 'r', ' ')>
        RIFFCPPO_char equ <mmioFOURCC('c', 'h', 'a', 'r')>
        RIFFCPPO_byte equ <mmioFOURCC('b', 'y', 't', 'e')>
        RIFFCPPO_int equ <mmioFOURCC('i', 'n', 't', ' ')>
        RIFFCPPO_word equ <mmioFOURCC('w', 'o', 'r', 'd')>
        RIFFCPPO_long equ <mmioFOURCC('l', 'o', 'n', 'g')>
        RIFFCPPO_dwrd equ <mmioFOURCC('d', 'w', 'r', 'd')>
        RIFFCPPO_flt equ <mmioFOURCC('f', 'l', 't', ' ')>
        RIFFCPPO_dbl equ <mmioFOURCC('d', 'b', 'l', ' ')>
        RIFFCPPO_str equ <mmioFOURCC('s', 't', 'r', ' ')>
      endif
      ifndef BI_BITFIELDS
        BI_BITFIELDS equ 3
      endif
      ifndef QUERYDIBSUPPORT
        QUERYDIBSUPPORT equ 3073
        QDI_SETDIBITS equ 0001h
        QDI_GETDIBITS equ 0002h
        QDI_DIBTOSCREEN equ 0004h
        QDI_STRETCHDIB equ 0008h
      endif
      ifndef NOBITMAP
        EXBMINFOHEADER struct
          bmi BITMAPINFOHEADER <>
          biExtDataOffset DWORD ?
        EXBMINFOHEADER ends
        tagEXBMINFOHEADER typedef EXBMINFOHEADER
      endif
      BICOMP_IBMULTIMOTION equ <mmioFOURCC('U', 'L', 'T', 'I')>
      BICOMP_IBMPHOTOMOTION equ <mmioFOURCC('P', 'H', 'M', 'O')>
      BICOMP_CREATIVEYUV equ <mmioFOURCC('c', 'y', 'u', 'v')>
      ifndef NOJPEGDIB
        JPEG_DIB equ <mmioFOURCC('J', 'P', 'E', 'G')>
        MJPG_DIB equ <mmioFOURCC('M', 'J', 'P', 'G')>
        JPEG_PROCESS_BASELINE equ 0
        AVIIF_CONTROLFRAME equ 00000200h
        JIFMK_SOF0 equ 0FFC0h
        JIFMK_SOF1 equ 0FFC1h
        JIFMK_SOF2 equ 0FFC2h
        JIFMK_SOF3 equ 0FFC3h
        JIFMK_SOF5 equ 0FFC5h
        JIFMK_SOF6 equ 0FFC6h
        JIFMK_SOF7 equ 0FFC7h
        JIFMK_JPG equ 0FFC8h
        JIFMK_SOF9 equ 0FFC9h
        JIFMK_SOF10 equ 0FFCAh
        JIFMK_SOF11 equ 0FFCBh
        JIFMK_SOF13 equ 0FFCDh
        JIFMK_SOF14 equ 0FFCEh
        JIFMK_SOF15 equ 0FFCFh
        JIFMK_DHT equ 0FFC4h
        JIFMK_DAC equ 0FFCCh
        JIFMK_RST0 equ 0FFD0h
        JIFMK_RST1 equ 0FFD1h
        JIFMK_RST2 equ 0FFD2h
        JIFMK_RST3 equ 0FFD3h
        JIFMK_RST4 equ 0FFD4h
        JIFMK_RST5 equ 0FFD5h
        JIFMK_RST6 equ 0FFD6h
        JIFMK_RST7 equ 0FFD7h
        JIFMK_SOI equ 0FFD8h
        JIFMK_EOI equ 0FFD9h
        JIFMK_SOS equ 0FFDAh
        JIFMK_DQT equ 0FFDBh
        JIFMK_DNL equ 0FFDCh
        JIFMK_DRI equ 0FFDDh
        JIFMK_DHP equ 0FFDEh
        JIFMK_EXP equ 0FFDFh
        JIFMK_APP0 equ 0FFE0h
        JIFMK_APP1 equ 0FFE1h
        JIFMK_APP2 equ 0FFE2h
        JIFMK_APP3 equ 0FFE3h
        JIFMK_APP4 equ 0FFE4h
        JIFMK_APP5 equ 0FFE5h
        JIFMK_APP6 equ 0FFE6h
        JIFMK_APP7 equ 0FFE7h
        JIFMK_JPG0 equ 0FFF0h
        JIFMK_JPG1 equ 0FFF1h
        JIFMK_JPG2 equ 0FFF2h
        JIFMK_JPG3 equ 0FFF3h
        JIFMK_JPG4 equ 0FFF4h
        JIFMK_JPG5 equ 0FFF5h
        JIFMK_JPG6 equ 0FFF6h
        JIFMK_JPG7 equ 0FFF7h
        JIFMK_JPG8 equ 0FFF8h
        JIFMK_JPG9 equ 0FFF9h
        JIFMK_JPG10 equ 0FFFAh
        JIFMK_JPG11 equ 0FFFBh
        JIFMK_JPG12 equ 0FFFCh
        JIFMK_JPG13 equ 0FFFDh
        JIFMK_COM equ 0FFFEh
        JIFMK_TEM equ 0FF01h
        JIFMK_RES equ 0FF02h
        JIFMK_00 equ 0FF00h
        JIFMK_FF equ 0FFFFh
        JPEG_Y equ 1
        JPEG_YCbCr equ 2
        JPEG_RGB equ 3
        JPEGINFOHEADER struct
          JPEGSize DWORD ?
          JPEGProcess DWORD ?
          JPEGColorSpaceID DWORD ?
          JPEGBitsPerSample DWORD ?
          JPEGHSubSampling DWORD ?
          JPEGVSubSampling DWORD ?
        JPEGINFOHEADER ends
        tagJPEGINFOHEADER typedef JPEGINFOHEADER
        ifdef MJPGDHTSEG_STORAGE
        endif
      endif
      ifndef NONEWIC
        ifndef ICTYPE_VIDEO
          ICTYPE_VIDEO equ <mmioFOURCC('v', 'i', 'd', 'c')>
          ICTYPE_AUDIO equ <mmioFOURCC('a', 'u', 'd', 'c')>
        endif
      endif
      FOURCC_RDSP equ <mmioFOURCC('R', 'D', 'S', 'P')>
      ifndef MMNOMIXER
        MIXERCONTROL_CONTROLTYPE_SRS_MTS equ (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 6)
        MIXERCONTROL_CONTROLTYPE_SRS_ONOFF equ (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 7)
        MIXERCONTROL_CONTROLTYPE_SRS_SYNTHSELECT equ (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 8)
      endif
    endif
    if  not Defined(RC_INVOKED) and Defined(_MSC_VER)
      if _MSC_VER le 800
      else
        include poppack.inc
      endif
    endif
    ifdef __cplusplus
      ;[...]
    endif
  endif
else
  ;[...]
endif
