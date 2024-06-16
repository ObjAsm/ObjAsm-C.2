;Include file created by h2inc+ version C.2.0 on (UTC) 15/06/2024 16:37:44
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\tcpestats.h
;             Created on (UTC) 22/05/2024 17:57:06
;             Last modified on (UTC) 08/01/2024 17:04:20

ifndef _TCPESTATS_
  _TCPESTATS_ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM or WINAPI_PARTITION_GAMES)
    TCP_ESTATS_TYPE typedef SDWORD
    TcpConnectionEstatsSynOpts equ 0
    TcpConnectionEstatsData equ 1
    TcpConnectionEstatsSndCong equ 2
    TcpConnectionEstatsPath equ 3
    TcpConnectionEstatsSendBuff equ 4
    TcpConnectionEstatsRec equ 5
    TcpConnectionEstatsObsRec equ 6
    TcpConnectionEstatsBandwidth equ 7
    TcpConnectionEstatsFineRtt equ 8
    TcpConnectionEstatsMaximum equ 9
    PTCP_ESTATS_TYPE typedef ptr TCP_ESTATS_TYPE
    TCP_BOOLEAN_OPTIONAL typedef SDWORD
    TcpBoolOptDisabled equ 0
    TcpBoolOptEnabled equ 1
    TcpBoolOptUnchanged equ -1
    _TCP_BOOLEAN_OPTIONAL typedef TCP_BOOLEAN_OPTIONAL
    PTCP_BOOLEAN_OPTIONAL typedef ptr TCP_BOOLEAN_OPTIONAL
    TCP_ESTATS_SYN_OPTS_ROS_v0 struct
      ActiveOpen BOOLEAN ?
      MssRcvd ULONG ?
      MssSent ULONG ?
    TCP_ESTATS_SYN_OPTS_ROS_v0 ends
    _TCP_ESTATS_SYN_OPTS_ROS_v0 typedef TCP_ESTATS_SYN_OPTS_ROS_v0
    PTCP_ESTATS_SYN_OPTS_ROS_v0 typedef ptr TCP_ESTATS_SYN_OPTS_ROS_v0
    TCP_SOFT_ERROR typedef SDWORD
    TcpErrorNone equ 0
    TcpErrorBelowDataWindow equ 1
    TcpErrorAboveDataWindow equ 2
    TcpErrorBelowAckWindow equ 3
    TcpErrorAboveAckWindow equ 4
    TcpErrorBelowTsWindow equ 5
    TcpErrorAboveTsWindow equ 6
    TcpErrorDataChecksumError equ 7
    TcpErrorDataLengthError equ 8
    TcpErrorMaxSoftError equ 9
    PTCP_SOFT_ERROR typedef ptr TCP_SOFT_ERROR
    TCP_ESTATS_DATA_ROD_v0 struct
      DataBytesOut ULONG64 ?
      DataSegsOut ULONG64 ?
      DataBytesIn ULONG64 ?
      DataSegsIn ULONG64 ?
      SegsOut ULONG64 ?
      SegsIn ULONG64 ?
      SoftErrors ULONG ?
      SoftErrorReason ULONG ?
      SndUna ULONG ?
      SndNxt ULONG ?
      SndMax ULONG ?
      ThruBytesAcked ULONG64 ?
      RcvNxt ULONG ?
      ThruBytesReceived ULONG64 ?
    TCP_ESTATS_DATA_ROD_v0 ends
    _TCP_ESTATS_DATA_ROD_v0 typedef TCP_ESTATS_DATA_ROD_v0
    PTCP_ESTATS_DATA_ROD_v0 typedef ptr TCP_ESTATS_DATA_ROD_v0
    TCP_ESTATS_DATA_RW_v0 struct
      EnableCollection BOOLEAN ?
    TCP_ESTATS_DATA_RW_v0 ends
    _TCP_ESTATS_DATA_RW_v0 typedef TCP_ESTATS_DATA_RW_v0
    PTCP_ESTATS_DATA_RW_v0 typedef ptr TCP_ESTATS_DATA_RW_v0
    TCP_ESTATS_SND_CONG_ROD_v0 struct
      SndLimTransRwin ULONG ?
      SndLimTimeRwin ULONG ?
      SndLimBytesRwin SIZE_T ?
      SndLimTransCwnd ULONG ?
      SndLimTimeCwnd ULONG ?
      SndLimBytesCwnd SIZE_T ?
      SndLimTransSnd ULONG ?
      SndLimTimeSnd ULONG ?
      SndLimBytesSnd SIZE_T ?
      SlowStart ULONG ?
      CongAvoid ULONG ?
      OtherReductions ULONG ?
      CurCwnd ULONG ?
      MaxSsCwnd ULONG ?
      MaxCaCwnd ULONG ?
      CurSsthresh ULONG ?
      MaxSsthresh ULONG ?
      MinSsthresh ULONG ?
    TCP_ESTATS_SND_CONG_ROD_v0 ends
    _TCP_ESTATS_SND_CONG_ROD_v0 typedef TCP_ESTATS_SND_CONG_ROD_v0
    PTCP_ESTATS_SND_CONG_ROD_v0 typedef ptr TCP_ESTATS_SND_CONG_ROD_v0
    TCP_ESTATS_SND_CONG_ROS_v0 struct
      LimCwnd ULONG ?
    TCP_ESTATS_SND_CONG_ROS_v0 ends
    _TCP_ESTATS_SND_CONG_ROS_v0 typedef TCP_ESTATS_SND_CONG_ROS_v0
    PTCP_ESTATS_SND_CONG_ROS_v0 typedef ptr TCP_ESTATS_SND_CONG_ROS_v0
    TCP_ESTATS_SND_CONG_RW_v0 struct
      EnableCollection BOOLEAN ?
    TCP_ESTATS_SND_CONG_RW_v0 ends
    _TCP_ESTATS_SND_CONG_RW_v0 typedef TCP_ESTATS_SND_CONG_RW_v0
    PTCP_ESTATS_SND_CONG_RW_v0 typedef ptr TCP_ESTATS_SND_CONG_RW_v0
    TCP_ESTATS_PATH_ROD_v0 struct
      FastRetran ULONG ?
      Timeouts ULONG ?
      SubsequentTimeouts ULONG ?
      CurTimeoutCount ULONG ?
      AbruptTimeouts ULONG ?
      PktsRetrans ULONG ?
      BytesRetrans ULONG ?
      DupAcksIn ULONG ?
      SacksRcvd ULONG ?
      SackBlocksRcvd ULONG ?
      CongSignals ULONG ?
      PreCongSumCwnd ULONG ?
      PreCongSumRtt ULONG ?
      PostCongSumRtt ULONG ?
      PostCongCountRtt ULONG ?
      EcnSignals ULONG ?
      EceRcvd ULONG ?
      SendStall ULONG ?
      QuenchRcvd ULONG ?
      RetranThresh ULONG ?
      SndDupAckEpisodes ULONG ?
      SumBytesReordered ULONG ?
      NonRecovDa ULONG ?
      NonRecovDaEpisodes ULONG ?
      AckAfterFr ULONG ?
      DsackDups ULONG ?
      SampleRtt ULONG ?
      SmoothedRtt ULONG ?
      RttVar ULONG ?
      MaxRtt ULONG ?
      MinRtt ULONG ?
      SumRtt ULONG ?
      CountRtt ULONG ?
      CurRto ULONG ?
      MaxRto ULONG ?
      MinRto ULONG ?
      CurMss ULONG ?
      MaxMss ULONG ?
      MinMss ULONG ?
      SpuriousRtoDetections ULONG ?
    TCP_ESTATS_PATH_ROD_v0 ends
    _TCP_ESTATS_PATH_ROD_v0 typedef TCP_ESTATS_PATH_ROD_v0
    PTCP_ESTATS_PATH_ROD_v0 typedef ptr TCP_ESTATS_PATH_ROD_v0
    TCP_ESTATS_PATH_RW_v0 struct
      EnableCollection BOOLEAN ?
    TCP_ESTATS_PATH_RW_v0 ends
    _TCP_ESTATS_PATH_RW_v0 typedef TCP_ESTATS_PATH_RW_v0
    PTCP_ESTATS_PATH_RW_v0 typedef ptr TCP_ESTATS_PATH_RW_v0
    TCP_ESTATS_SEND_BUFF_ROD_v0 struct
      CurRetxQueue SIZE_T ?
      MaxRetxQueue SIZE_T ?
      CurAppWQueue SIZE_T ?
      MaxAppWQueue SIZE_T ?
    TCP_ESTATS_SEND_BUFF_ROD_v0 ends
    _TCP_ESTATS_SEND_BUFF_ROD_v0 typedef TCP_ESTATS_SEND_BUFF_ROD_v0
    PTCP_ESTATS_SEND_BUFF_ROD_v0 typedef ptr TCP_ESTATS_SEND_BUFF_ROD_v0
    TCP_ESTATS_SEND_BUFF_RW_v0 struct
      EnableCollection BOOLEAN ?
    TCP_ESTATS_SEND_BUFF_RW_v0 ends
    _TCP_ESTATS_SEND_BUFF_RW_v0 typedef TCP_ESTATS_SEND_BUFF_RW_v0
    PTCP_ESTATS_SEND_BUFF_RW_v0 typedef ptr TCP_ESTATS_SEND_BUFF_RW_v0
    TCP_ESTATS_REC_ROD_v0 struct
      CurRwinSent ULONG ?
      MaxRwinSent ULONG ?
      MinRwinSent ULONG ?
      LimRwin ULONG ?
      DupAckEpisodes ULONG ?
      DupAcksOut ULONG ?
      CeRcvd ULONG ?
      EcnSent ULONG ?
      EcnNoncesRcvd ULONG ?
      CurReasmQueue ULONG ?
      MaxReasmQueue ULONG ?
      CurAppRQueue SIZE_T ?
      MaxAppRQueue SIZE_T ?
      WinScaleSent UCHAR ?
    TCP_ESTATS_REC_ROD_v0 ends
    _TCP_ESTATS_REC_ROD_v0 typedef TCP_ESTATS_REC_ROD_v0
    PTCP_ESTATS_REC_ROD_v0 typedef ptr TCP_ESTATS_REC_ROD_v0
    TCP_ESTATS_REC_RW_v0 struct
      EnableCollection BOOLEAN ?
    TCP_ESTATS_REC_RW_v0 ends
    _TCP_ESTATS_REC_RW_v0 typedef TCP_ESTATS_REC_RW_v0
    PTCP_ESTATS_REC_RW_v0 typedef ptr TCP_ESTATS_REC_RW_v0
    TCP_ESTATS_OBS_REC_ROD_v0 struct
      CurRwinRcvd ULONG ?
      MaxRwinRcvd ULONG ?
      MinRwinRcvd ULONG ?
      WinScaleRcvd UCHAR ?
    TCP_ESTATS_OBS_REC_ROD_v0 ends
    _TCP_ESTATS_OBS_REC_ROD_v0 typedef TCP_ESTATS_OBS_REC_ROD_v0
    PTCP_ESTATS_OBS_REC_ROD_v0 typedef ptr TCP_ESTATS_OBS_REC_ROD_v0
    TCP_ESTATS_OBS_REC_RW_v0 struct
      EnableCollection BOOLEAN ?
    TCP_ESTATS_OBS_REC_RW_v0 ends
    _TCP_ESTATS_OBS_REC_RW_v0 typedef TCP_ESTATS_OBS_REC_RW_v0
    PTCP_ESTATS_OBS_REC_RW_v0 typedef ptr TCP_ESTATS_OBS_REC_RW_v0
    TCP_ESTATS_BANDWIDTH_RW_v0 struct
      EnableCollectionOutbound TCP_BOOLEAN_OPTIONAL ?
      EnableCollectionInbound TCP_BOOLEAN_OPTIONAL ?
    TCP_ESTATS_BANDWIDTH_RW_v0 ends
    _TCP_ESTATS_BANDWIDTH_RW_v0 typedef TCP_ESTATS_BANDWIDTH_RW_v0
    PTCP_ESTATS_BANDWIDTH_RW_v0 typedef ptr TCP_ESTATS_BANDWIDTH_RW_v0
    TCP_ESTATS_BANDWIDTH_ROD_v0 struct
      OutboundBandwidth ULONG64 ?
      InboundBandwidth ULONG64 ?
      OutboundInstability ULONG64 ?
      InboundInstability ULONG64 ?
      OutboundBandwidthPeaked BOOLEAN ?
      InboundBandwidthPeaked BOOLEAN ?
    TCP_ESTATS_BANDWIDTH_ROD_v0 ends
    _TCP_ESTATS_BANDWIDTH_ROD_v0 typedef TCP_ESTATS_BANDWIDTH_ROD_v0
    PTCP_ESTATS_BANDWIDTH_ROD_v0 typedef ptr TCP_ESTATS_BANDWIDTH_ROD_v0
    TCP_ESTATS_FINE_RTT_RW_v0 struct
      EnableCollection BOOLEAN ?
    TCP_ESTATS_FINE_RTT_RW_v0 ends
    _TCP_ESTATS_FINE_RTT_RW_v0 typedef TCP_ESTATS_FINE_RTT_RW_v0
    PTCP_ESTATS_FINE_RTT_RW_v0 typedef ptr TCP_ESTATS_FINE_RTT_RW_v0
    TCP_ESTATS_FINE_RTT_ROD_v0 struct
      RttVar ULONG ?
      MaxRtt ULONG ?
      MinRtt ULONG ?
      SumRtt ULONG ?
    TCP_ESTATS_FINE_RTT_ROD_v0 ends
    _TCP_ESTATS_FINE_RTT_ROD_v0 typedef TCP_ESTATS_FINE_RTT_ROD_v0
    PTCP_ESTATS_FINE_RTT_ROD_v0 typedef ptr TCP_ESTATS_FINE_RTT_ROD_v0
  endif
endif
