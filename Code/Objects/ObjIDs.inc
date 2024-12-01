; ==================================================================================================
; Title:      ObjIDs.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm object IDs.
; Notes:      To avoid ID duplications, all ObjAsm object IDs should be defined here.
;             User Object IDs should be defined in an independant file and the values should be
;             above 80000000h.
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; ==================================================================================================
;    Object ID equates
; ==================================================================================================

;Primer object
PrimerID                          equ     0000000001

;Array objects
ArrayID                           equ     0000000005
MatrixID                          equ     0000000006

;Stream objects
StreamableID                      equ     0000000010
StreamID                          equ     0000000011
DesLUTID                          equ     0000000012
DiskStreamID                      equ     0000000013
BufferedDiskStreamID              equ     0000000014
MemoryStreamID                    equ     0000000015
EditStreamID                      equ     0000000016

;Collection objects
CollectionID                      equ     0000000020
SortedCollectionID                equ     0000000021
StrCollectionAID                  equ     0000000022
StrCollectionWID                  equ     0000000023
DataCollectionID                  equ     0000000024
SortedStrCollectionAID            equ     0000000025
SortedStrCollectionWID            equ     0000000026
SortedDataCollectionID            equ     0000000027
XWCollectionID                    equ     0000000028

;Profiling objects
TickCounterID                     equ     0000000040
StopWatchID                       equ     0000000041

;Ini File object (IniFile.inc)
IniFileID                         equ     0000000050

;CRC objects
CRC_16ID                          equ     0000000060
CRC_32ID                          equ     0000000061

;Vector Objects
VectorID                          equ     0000000070
ByteVectorID                      equ     0000000071
WordVectorID                      equ     0000000072
DWordVectorID                     equ     0000000073
QWordVectorID                     equ     0000000074
OWordVectorID                     equ     0000000075
Real4VectorID                     equ     0000000076
Real8VectorID                     equ     0000000077
DataVectorID                      equ     0000000078

SortedVectorID                    equ     0000000080
SortedByteVectorID                equ     0000000081
SortedWordVectorID                equ     0000000082
SortedDWordVectorID               equ     0000000083
SortedQWordVectorID               equ     0000000084
SortedOWordVectorID               equ     0000000085
SortedReal4VectorID               equ     0000000086
SortedReal8VectorID               equ     0000000087
SortedDataVectorID                equ     0000000088

;Windows primer objects
WinPrimerID                       equ     0000000100
MsgInterceptorID                  equ     0000000101

;Windows control objects
WinControlID                      equ     0000000110
ToolbarID                         equ     0000000111
StatusbarID                       equ     0000000112
TooltipID                         equ     0000000113
BandFrameID                       equ     0000000114
RbIptorID                         equ     0000000115
RebarID                           equ     0000000116
ProgressbarID                     equ     0000000117
TrayIconID                        equ     0000000128
TreeViewID                        equ     0000000129
ListViewID                        equ     0000000130
ComboBoxID                        equ     0000000131
TabCtrlID                         equ     0000000132
ScrollBarID                       equ     0000000133

;ImageList objects
SimpleImageListID                 equ     0000000150
MaskedImageListID                 equ     0000000151

;Windows application objects
WinAppID                          equ     0000000160
SdiAppID                          equ     0000000161
MdiAppID                          equ     0000000162
MdiClientWndID                    equ     0000000163
MdiChildWndID                     equ     0000000164
MdiChildDlgID                     equ     0000000165
WindowID                          equ     0000000166
DlgAppID                          equ     0000000167
ConsoleAppID                      equ     0000000168

ApplicationID                     equ     0000000170
ClientWndID                     equ     0000000172      ;for test or demo purposes only!
ChildWndID                      equ     0000000173      ;for test or demo purposes only!

;Windows dialog objects
DialogID                          equ     0000000180
DialogModalID                     equ     0000000181
DialogModelessID                  equ     0000000182
DialogRollingID                   equ     0000000183
DialogModalIndirectID             equ     0000000184
DialogModelessIndirectID          equ     0000000185
DialogFindTextID                  equ     0000000186
DynLayDlgModalID                  equ     0000000187
DynLayDlgModelessID               equ     0000000188

DialogAboutID                     equ     0000000190
DialogAboutIndirectID             equ     0000000191

DialogPasswordID                  equ     0000000195

SkinnedMsgBoxID                   equ     0000000200
SkinnedDialogAboutID              equ     0000000201

;Registry objects
RegKeyID                          equ     0000000250

;XMenu objects
XMenuID                           equ     0000000260
XMenuItemID                       equ     0000000261
XMdiMenuID                        equ     0000000262
XMenuSelectDlgID                  equ     0000000263

;Data buffering objects
ChartSeriesID                     equ     0000000270
ChartXYSeriesID                   equ     0000000271
ChartBarSeriesID                  equ     0000000272

DataBufferXYID                    equ     0000000275                  ;deprecated

;Plot objects
ChartWndID                        equ     0000000280
ChartXYWndID                      equ     0000000281
ChartBarWndID                     equ     0000000282
PlotXYID                          equ     0000000285                  ;deprecated

;Buttons objects
ButtonID                          equ     0000000300
IconButtonID                      equ     0000000301
RgnButtonID                       equ     0000000302

ColorButtonID                     equ     0000000305

;GIFs
GifDecoderID                      equ     0000000350
GifPlayerID                       equ     0000000351
GifFrameID                        equ     0000000352

;ImageDecoders
PngDecoderID                      equ     0000000355
JpgDecoderID                      equ     0000000356

;Magmetism (Magnetism.inc)
MagnetismID                       equ     0000000360

;Spliters
SplitterID                        equ     0000000362

;Hyperlink
HyperlinkID                       equ     0000000364

;Window Skins
SkinID                            equ     0000000367
ElasticSkinID                     equ     0000000368

;Throbbers
ThrobberID                        equ     0000000370
SpinningThrobberID                equ     0000000371
MovingThrobberID                  equ     0000000372

;3D Engine
D3VectronCollectionID             equ     0000000400
D3TriangleID                      equ     0000000401
D3ObjectID                        equ     0000000402
D3CameraID                        equ     0000000403
D3LightID                         equ     0000000404
D3SceneID                         equ     0000000405
D3StreamID                        equ     0000000406

;Ole Data Base
OleDBID                           equ     0000000450

;Shell ID Lists
IDLID                             equ     0000000480

;Hooking objects
IAT32HookID                       equ     0000000490
IAT64HookID                       equ     0000000491

;RadASM objects
RA_AddinID                        equ     0000000500
RA_TextSourceID                   equ     0000000501
RA_MethodSetupID                  equ     0000000502
RA_FloatID                        equ     0000000503
RA_OA_AddinID                     equ     0000000510

;Linked List objects
LinkedListID                      equ     0000000600
LinkedMemberID                    equ     0000000601
LinkedMemberListID                equ     0000000602

;IoPort
IoPortID                          equ     0000000610

;Splash Window
SplashID                          equ     0000000620

;Compression objects
NTCompressorID                    equ     0000000630
NTFileCompressorID                equ     0000000640

;Pixelmap
PixelmapID                        equ     0000000660

;DataPool
DataPoolID                        equ     0000000670

;MemHeap
MemHeapID                         equ     0000000675
MemHeapPoolID                     equ     0000000676

;StringManager
StringManagerID                   equ     0000000680

;SAPI objects
TextToSpeechID                    equ     0000000690

;MSChart objects
MSChartID                         equ     0000000700
IMSChartEventsID                  equ     0000000701

;HashMD5
HashMD5ID                         equ     0000000705

;Perl compatible regular expressions
RegExAID                          equ     0000000710
RegExWID                          equ     0000000711

;Autobuffer object
AutobufferID                      equ     0000000720

;HashMap object
HashMapID                         equ     0000000730


;COM specific objects
ComponentID                       equ     0000010000
ClassFactoryID                    equ     0000010001
InProcServerID                    equ     0000010002
IUnknownID                        equ     0000010003
IUnknownNoDelegateID              equ     0000010004
IClassFactoryID                   equ     0000010005
IDispatchID                       equ     0000010006
ITypeInfoID                       equ     0000010007
ITypeLibID                        equ     0000010008
IDualID                           equ     0000010009

IMarshalID                        equ     0000010010
IUnmarshalID                      equ     0000010011
IStdMarshalInfoID                 equ     0000010012
IExternalConnectionID             equ     0000010013

ConnectionPointID                 equ     0000010020
EnumConnectionPointsID            equ     0000010021
EnumConnectionsID                 equ     0000010022
IConnectionPointContainerID       equ     0000010023
IConnectionPointID                equ     0000010024
IEnumConnectionPointsID           equ     0000010025
IEnumConnectionsID                equ     0000010026

IOleObjectID                      equ     0000010030
IProvideClassInfoID               equ     0000010031
IProvideClassInfo2ID              equ     0000010032
IPersistID                        equ     0000010033
IPersistStreamID                  equ     0000010034
IPersistStreamInitID              equ     0000010035
IViewObjectID                     equ     0000010036
IViewObject2ID                    equ     0000010037
ISpecifyPropertyPagesID           equ     0000010038
IPersistPropertyBagID             equ     0000010039
ICategorizePropertiesID           equ     0000010040
IClientSiteID                     equ     0000010041
IAdviseSinkID                     equ     0000010042
IOleAdviseHolderID                equ     0000010043
IOleControlSiteID                 equ     0000010044
IOleWindowID                      equ     0000010045
ISequentialStreamID               equ     0000010046
IStreamID                         equ     0000010047
IPropertyBagID                    equ     0000010048
ISupportErrorInfoID               equ     0000010049
PropertyPageID                    equ     0000010050
IPropertyPageID                   equ     0000010051
IPropertyPage2ID                  equ     0000010052
IPerPropertyBrowsingID            equ     0000010053
IPropertyNotifySinkID             equ     0000010054
IOleInPlaceObjectID               equ     0000010055
EnumVARIANTID                     equ     0000010056
IEnumVARIANTID                    equ     0000010057

;XML objects
ISAXContentHandlerID              equ     0000010100
XML3DContentHandlerID             equ     0000010101
XML3DObjectID                     equ     0000010102

;SharedMemoryObject
SharedMemoryObjectID              equ     0000010105

;Xtreeview
XTreeViewID                       equ     0000010110
XTreeViewNodeID                   equ     0000010111

;XPropertyTree
XPropertyTreeID                   equ     0000010120
XPT_CategoryNodeID                equ     0000010121
XPT_PropertyNodeID                equ     0000010122
XPT_EditID                        equ     0000010123
XPT_ButtonID                      equ     0000010124
XPT_ComboBoxID                    equ     0000010125

;EventManager
EventManagerID                    equ     0000010130
EventBankID                       equ     0000010131

;DirectX specific and related objects
Direct3DID                        equ     0000011000
DialogDXSetupID                   equ     0000011001
D3D_VertexBufferID                equ     0000011002
D3D_IndexBufferID                 equ     0000011003
D3D_TextureManagerID              equ     0000011004
D3D_MeshID                        equ     0000011005
D3D_CameraID                      equ     0000011006
D3D_FontID                        equ     0000011007
D3D_ParticleSystemID              equ     0000011008
D3D_SmokeID                       equ     0000011009
D3D_SnowfallID                    equ     0000011010
D3D_LaserBeamID                   equ     0000011011
D3D_MeshManagerID                 equ     0000011012
D3D_MeshManagedID                 equ     0000011013
D3D_WindowID                      equ     0000011014
D3D_ApplicationID                 equ     0000011015
D3D_VectorManagerID               equ     0000011016
D3D_VectorGroupID                 equ     0000011017
D3D_SkinMeshID                    equ     0000011018
D3D_SkinMeshInstanceID            equ     0000011019
D3D_SkinMeshManagerID             equ     0000011020
SoundID                           equ     0000011021
SoundInID                         equ     0000011022
StreamingSoundID                  equ     0000011023
StreamingSoundInID                equ     0000011024
StreamingMP3SoundID               equ     0000011025
StreamingMP3SoundInID             equ     0000011026
D3D_AudioID                       equ     0000011027
Vec4CollectionID                  equ     0000011028
D3D_SpriteManagerID               equ     0000011029
D3D_AudioEmitterID                equ     0000011030
D3D_Camera2ID                     equ     0000011031
DirectInputID                     equ     0000011100

;Scripting objects
ScriptHostID                      equ     0000012000
IActiveScriptSiteID               equ     0000012001
IActiveScriptSiteWindowID         equ     0000012002
IActiveScriptSiteDebugID          equ     0000012003
IScriptInterfaceID                equ     0000012004

;Lua Host
LuaHostID                         equ     0000012008

;OCX container
OcxContainerID                    equ     0000012010
OcxClientSiteID                   equ     0000012011

;RedBlackTree
RedBlackTreeID                    equ     0000012030

;OA Object Explorer
OAE_FilesCollectionID             equ     0000012040
OAE_ObjInfoCollectionID           equ     0000012041
OAE_ObjMtdInfoCollectionID        equ     0000012042
OAE_ObjVarInfoCollectionID        equ     0000012043
OAE_IntInfoCollectionID           equ     0000012044
OAE_IntMtdInfoCollectionID        equ     0000012045
OAE_ImpMtdInfoCollectionID        equ     0000012046
OAE_ObjDBID                       equ     0000012047
OAE_ClientWndID                   equ     0000012048
OAE_PropWndID                     equ     0000012049
OAE_IntPropWndID                  equ     0000012050
OAE_ObjPropWndID                  equ     0000012051
OAE_ApplicationID                 equ     0000012052

;Office apps
ExcelHostID                       equ     0000012060
WordHostID                        equ     0000012061
OutlookHostID                     equ     0000012062
PowerPointHostID                  equ     0000012063

;NetCom
NetComIOSockJobPoolID             equ     0000012100
NetComIOFileJobPoolID             equ     0000012101
NetComIOMsgPoolID                 equ     0000012102
NetComConnectionID                equ     0000012103
NetComConnectionPoolID            equ     0000012104
NetComEngineID                    equ     0000012105
NetComProtocolID                  equ     0000012106
NetComFileID                      equ     0000012107
NetComFileEventsID                equ     0000012108

;CodeEditor
CodeEditorID                      equ     0000012200
CodeEditorViewID                  equ     0000012201
CodeEditorTextLineID              equ     0000012202
KeywordListID                     equ     0000012203

;Database objects (DataBase.inc)
DB_FieldID                        equ     0000012300
DB_RecordID                       equ     0000012301
DB_RecordCacheID                  equ     0000012302
DB_TableID                        equ     0000012303
DB_IndexID                        equ     0000012304
DB_MemoID                         equ     0000012305
DB_MemoBlockID                    equ     0000012306
DB_MemoBlockCacheID               equ     0000012307
DB_RecordEditorID                 equ     0000012308
DB_RecordEditorLineID             equ     0000012309
DB_StructEditorID                 equ     0000012310
DB_StructEditorLineID             equ     0000012311
NdxMemBlockID                     equ     0000012312
NdxBlockCacheID                   equ     0000012313
DB_QueryID                        equ     0000012314

;Image
ImageID                           equ     0000012500

;FlipBox
FlipBoxID                         equ     0000012510

;TextView
TextViewID                        equ     0000012520

;GridView
GridViewID                        equ     0000012530

;JSON
JsonID                            equ     0000012540

;HttpServer
HttpServerID                      equ     0000012550

;WindowBackground
WindowBackgroundID                equ     0000012560

;Dictionary
DictionaryID                      equ     0000012580

;WebTranslator
WebTextTranslatorID               equ     0000012590

;Math
FFTID                             equ     0000012600

;ODBC
ODBCID                            equ     0000012700

;XLMDOM
XmlDocumentID                     equ     0000012720
XmlNodeID                         equ     0000012721
