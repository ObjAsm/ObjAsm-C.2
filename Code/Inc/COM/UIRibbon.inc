; ==================================================================================================
; Title:      UIRibbon.inc
; Original:   UIRibbon.h
; Version:    C.1.0
; Author:     G. Friedrich
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


DEFINE_UIPROPERTYKEY macro PropName, PropID, Index
  PropName PROPERTYKEY {{Index,07363h,0696eh, {084h,041h,079h,08ah,0cfh,05ah,0ebh,0b7h}}, PropID}
endm

.const
DEFINE_UIPROPERTYKEY UI_PKEY_Enabled,                            VT_BOOL,                1
DEFINE_UIPROPERTYKEY UI_PKEY_LabelDescription,                   VT_LPWSTR,              2
DEFINE_UIPROPERTYKEY UI_PKEY_Keytip,                             VT_LPWSTR,              3
DEFINE_UIPROPERTYKEY UI_PKEY_Label,                              VT_LPWSTR,              4
DEFINE_UIPROPERTYKEY UI_PKEY_TooltipDescription,                 VT_LPWSTR,              5
DEFINE_UIPROPERTYKEY UI_PKEY_TooltipTitle,                       VT_LPWSTR,              6
DEFINE_UIPROPERTYKEY UI_PKEY_LargeImage,                         VT_UNKNOWN,             7
DEFINE_UIPROPERTYKEY UI_PKEY_LargeHighContrastImage,             VT_UNKNOWN,             8
DEFINE_UIPROPERTYKEY UI_PKEY_SmallImage,                         VT_UNKNOWN,             9
DEFINE_UIPROPERTYKEY UI_PKEY_SmallHighContrastImage,             VT_UNKNOWN,             10
DEFINE_UIPROPERTYKEY UI_PKEY_CommandId,                          VT_UI4,                 100
DEFINE_UIPROPERTYKEY UI_PKEY_ItemsSource,                        VT_UNKNOWN,             101
DEFINE_UIPROPERTYKEY UI_PKEY_Categories,                         VT_UNKNOWN,             102
DEFINE_UIPROPERTYKEY UI_PKEY_CategoryId,                         VT_UI4,                 103
DEFINE_UIPROPERTYKEY UI_PKEY_SelectedItem,                       VT_UI4,                 104
DEFINE_UIPROPERTYKEY UI_PKEY_CommandType,                        VT_UI4,                 105
DEFINE_UIPROPERTYKEY UI_PKEY_ItemImage,                          VT_UNKNOWN,             106
DEFINE_UIPROPERTYKEY UI_PKEY_BooleanValue,                       VT_BOOL,                200
DEFINE_UIPROPERTYKEY UI_PKEY_DecimalValue,                       VT_DECIMAL,             201
DEFINE_UIPROPERTYKEY UI_PKEY_StringValue,                        VT_LPWSTR,              202
DEFINE_UIPROPERTYKEY UI_PKEY_MaxValue,                           VT_DECIMAL,             203
DEFINE_UIPROPERTYKEY UI_PKEY_MinValue,                           VT_DECIMAL,             204
DEFINE_UIPROPERTYKEY UI_PKEY_Increment,                          VT_DECIMAL,             205
DEFINE_UIPROPERTYKEY UI_PKEY_DecimalPlaces,                      VT_UI4,                 206
DEFINE_UIPROPERTYKEY UI_PKEY_FormatString,                       VT_LPWSTR,              207
DEFINE_UIPROPERTYKEY UI_PKEY_RepresentativeString,               VT_LPWSTR,              208
DEFINE_UIPROPERTYKEY UI_PKEY_FontProperties,                     VT_UNKNOWN,             300
DEFINE_UIPROPERTYKEY UI_PKEY_FontProperties_Family,              VT_LPWSTR,              301
DEFINE_UIPROPERTYKEY UI_PKEY_FontProperties_Size,                VT_DECIMAL,             302
DEFINE_UIPROPERTYKEY UI_PKEY_FontProperties_Bold,                VT_UI4,                 303
DEFINE_UIPROPERTYKEY UI_PKEY_FontProperties_Italic,              VT_UI4,                 304
DEFINE_UIPROPERTYKEY UI_PKEY_FontProperties_Underline,           VT_UI4,                 305
DEFINE_UIPROPERTYKEY UI_PKEY_FontProperties_Strikethrough,       VT_UI4,                 306
DEFINE_UIPROPERTYKEY UI_PKEY_FontProperties_VerticalPositioning, VT_UI4,                 307
DEFINE_UIPROPERTYKEY UI_PKEY_FontProperties_ForegroundColor,     VT_UI4,                 308
DEFINE_UIPROPERTYKEY UI_PKEY_FontProperties_BackgroundColor,     VT_UI4,                 309
DEFINE_UIPROPERTYKEY UI_PKEY_FontProperties_ForegroundColorType, VT_UI4,                 310
DEFINE_UIPROPERTYKEY UI_PKEY_FontProperties_BackgroundColorType, VT_UI4,                 311
DEFINE_UIPROPERTYKEY UI_PKEY_FontProperties_ChangedProperties,   VT_UNKNOWN,             312
DEFINE_UIPROPERTYKEY UI_PKEY_FontProperties_DeltaSize,           VT_UI4,                 313
DEFINE_UIPROPERTYKEY UI_PKEY_RecentItems,                        VT_ARRAY or VT_UNKNOWN, 350
DEFINE_UIPROPERTYKEY UI_PKEY_Pinned,                             VT_BOOL,                351
DEFINE_UIPROPERTYKEY UI_PKEY_Color,                              VT_UI4,                 400
DEFINE_UIPROPERTYKEY UI_PKEY_ColorType,                          VT_UI4,                 401
DEFINE_UIPROPERTYKEY UI_PKEY_ColorMode,                          VT_UI4,                 402
DEFINE_UIPROPERTYKEY UI_PKEY_ThemeColorsCategoryLabel,           VT_LPWSTR,              403
DEFINE_UIPROPERTYKEY UI_PKEY_StandardColorsCategoryLabel,        VT_LPWSTR,              404
DEFINE_UIPROPERTYKEY UI_PKEY_RecentColorsCategoryLabel,          VT_LPWSTR,              405
DEFINE_UIPROPERTYKEY UI_PKEY_AutomaticColorLabel,                VT_LPWSTR,              406
DEFINE_UIPROPERTYKEY UI_PKEY_NoColorLabel,                       VT_LPWSTR,              407
DEFINE_UIPROPERTYKEY UI_PKEY_MoreColorsLabel,                    VT_LPWSTR,              408
DEFINE_UIPROPERTYKEY UI_PKEY_ThemeColors,                        VT_VECTOR or VT_UI4,    409
DEFINE_UIPROPERTYKEY UI_PKEY_StandardColors,                     VT_VECTOR or VT_UI4,    410
DEFINE_UIPROPERTYKEY UI_PKEY_ThemeColorsTooltips,                VT_VECTOR or VT_LPWSTR, 411
DEFINE_UIPROPERTYKEY UI_PKEY_StandardColorsTooltips,             VT_VECTOR or VT_LPWSTR, 412
DEFINE_UIPROPERTYKEY UI_PKEY_Viewable,                           VT_BOOL,                1000
DEFINE_UIPROPERTYKEY UI_PKEY_Minimized,                          VT_BOOL,                1001
DEFINE_UIPROPERTYKEY UI_PKEY_QuickAccessToolbarDock,             VT_UI4,                 1002
DEFINE_UIPROPERTYKEY UI_PKEY_ContextAvailable,                   VT_UI4,                 1100
DEFINE_UIPROPERTYKEY UI_PKEY_GlobalBackgroundColor,              VT_UI4,                 2000
DEFINE_UIPROPERTYKEY UI_PKEY_GlobalHighlightColor,               VT_UI4,                 2001
DEFINE_UIPROPERTYKEY UI_PKEY_GlobalTextColor,                    VT_UI4,                 2002


;UI_CONTEXTAVAILABILITY
UI_CONTEXTAVAILABILITY_NOTAVAILABLE   equ 0
UI_CONTEXTAVAILABILITY_AVAILABLE      equ 1
UI_CONTEXTAVAILABILITY_ACTIVE         equ 2

;UI_FONTPROPERTIES
UI_FONTPROPERTIES_NOTAVAILABLE        equ 0
UI_FONTPROPERTIES_NOTSET              equ 1
UI_FONTPROPERTIES_SET                 equ 2

;UI_FONTVERTICALPOSITION
UI_FONTVERTICALPOSITION_NOTAVAILABLE  equ 0
UI_FONTVERTICALPOSITION_NOTSET        equ 1
UI_FONTVERTICALPOSITION_SUPERSCRIPT   equ 2
UI_FONTVERTICALPOSITION_SUBSCRIPT     equ 3

;UI_FONTUNDERLINE
UI_FONTUNDERLINE_NOTAVAILABLE         equ 0
UI_FONTUNDERLINE_NOTSET               equ 1
UI_FONTUNDERLINE_SET                  equ 2

;UI_FONTDELTASIZE
UI_FONTDELTASIZE_GROW                 equ 0
UI_FONTDELTASIZE_SHRINK               equ 1

;UI_CONTROLDOCK
UI_CONTROLDOCK_TOP                    equ 1
UI_CONTROLDOCK_BOTTOM                 equ 3

;UI_SWATCHCOLORTYPE
UI_SWATCHCOLORTYPE_NOCOLOR            equ 0
UI_SWATCHCOLORTYPE_AUTOMATIC          equ 1
UI_SWATCHCOLORTYPE_RGB                equ 2

;UI_SWATCHCOLORMODE
UI_SWATCHCOLORMODE_NORMAL             equ 0
UI_SWATCHCOLORMODE_MONOCHROME         equ 1

;UI_EVENTTYPE
UI_EVENTTYPE_ApplicationMenuOpened    equ 0
UI_EVENTTYPE_RibbonMinimized          equ 1
UI_EVENTTYPE_RibbonExpanded           equ 2
UI_EVENTTYPE_ApplicationModeSwitched  equ 3
UI_EVENTTYPE_TabActivated             equ 4
UI_EVENTTYPE_MenuOpened               equ 5
UI_EVENTTYPE_CommandExecuted          equ 6
UI_EVENTTYPE_TooltipShown             equ 7

;UI_EVENTLOCATION
UI_EVENTLOCATION_Ribbon               equ 0
UI_EVENTLOCATION_QAT                  equ 1
UI_EVENTLOCATION_ApplicationMenu      equ 2
UI_EVENTLOCATION_ContextPopup         equ 3


COM_INTERFACE_BEG IUISimplePropertySet, IUnknown, <C205BB48-5B1C-4219-A106-15BD0A5F24E2>
  COM_MTD_STD   GetValue,                 :POINTER, :POINTER
COM_INTERFACE_END


COM_INTERFACE_BEG IUIRibbon, IUnknown, <803982AB-370A-4F7E-A9E7-8784036A6E26>
  COM_MTD_STD   GetHeight,                :POINTER
  COM_MTD_STD   LoadSettingsFromStream,   :POINTER
  COM_MTD_STD   SaveSettingsToStream,     :POINTER
COM_INTERFACE_END


;UI_INVALIDATIONS
UI_INVALIDATIONS_STATE                equ 1
UI_INVALIDATIONS_VALUE                equ 2
UI_INVALIDATIONS_PROPERTY             equ 4
UI_INVALIDATIONS_ALLPROPERTIES        equ 8

COM_INTERFACE_BEG IUIFramework, IUnknown, <F4F0385D-6872-43A8-AD09-4C339CB3F5C5>
  COM_MTD_STD   Initialize,               :HWND, :POINTER
  COM_MTD_STD   Destroy
  COM_MTD_STD   LoadUI,                   :HINSTANCE, :PSTRINGW
  COM_MTD_STD   GetView,                  :DWORD, :POINTER
  COM_MTD_STD   GetUICommandProperty,     :POINTER, :POINTER
  COM_MTD_STD   SetUICommandProperty,     :POINTER, :POINTER
  COM_MTD_STD   InvalidateUICommand,      :DWORD, :DWORD
  COM_MTD_STD   FlushPendingInvalidations,:DWORD, :DWORD
  COM_MTD_STD   SetModes,                 :DWORD
COM_INTERFACE_END


UI_EVENTPARAMS_COMMAND struc
  CommandID         DWORD     ?
  CommandName       PSTRINGW  ?
  ParentCommandID   DWORD     ?
  ParentCommandName PSTRINGW  ?
  SelectionIndex    DWORD     ?
  Location          DWORD     ?
UI_EVENTPARAMS_COMMAND ends

UI_EVENTPARAMS struc
  EventType         DWORD     ?
  union
    Modes           DWORD     ?
    Params          DWORD     ?
  ends
UI_EVENTPARAMS ends


COM_INTERFACE_BEG IUIEventLogger, IUnknown, <EC3E1034-DBF4-41A1-95D5-03E0F1026E05>
  COM_MTD_STD   OnUIEvent,                :POINTER
COM_INTERFACE_END

COM_INTERFACE_BEG IUIEventingManager, IUnknown, <3BE6EA7F-9A9B-4198-9368-9B0F923BD534>
  COM_MTD_STD   SetEventLogger,           :POINTER
COM_INTERFACE_END

COM_INTERFACE_BEG IUIContextualUI, IUnknown, <EEA11F37-7C46-437C-8E55-B52122B29293>
  COM_MTD_STD   ShowAtLocation,           :DWORD, :DWORD
COM_INTERFACE_END

COM_INTERFACE_BEG IUICollection, IUnknown, <DF4F45BF-6F9D-4dd7-9D68-D8F9CD18C4DB>
  COM_MTD_STD   GetCount,                 :DWORD
  COM_MTD_STD   GetItem,                  :DWORD, :POINTER
  COM_MTD_STD   Add_,                     :POINTER
  COM_MTD_STD   Insert,                   :DWORD, :POINTER
  COM_MTD_STD   RemoveAt,                 :DWORD
  COM_MTD_STD   Replace,                  :DWORD, :POINTER
  COM_MTD_STD   Clear
COM_INTERFACE_END

;UI_COLLECTIONCHANGE
UI_COLLECTIONCHANGE_INSERT        equ 0
UI_COLLECTIONCHANGE_REMOVE        equ 1
UI_COLLECTIONCHANGE_REPLACE       equ 2
UI_COLLECTIONCHANGE_RESET         equ 3

UI_COLLECTION_INVALIDINDEX        equ 0FFFFFFFFh

COM_INTERFACE_BEG IUICollectionChangedEvent, IUnknown, <6502AE91-A14D-44B5-BBD0-62AACC581D52>
  COM_MTD_STD   OnChanged,                :DWORD, :DWORD, :POINTER, :DWORD, :POINTER
COM_INTERFACE_END


;UI_EXECUTIONVERB
UI_EXECUTIONVERB_EXECUTE          equ 0
UI_EXECUTIONVERB_PREVIEW          equ 1
UI_EXECUTIONVERB_CANCELPREVIEW    equ 2

COM_INTERFACE_BEG IUICommandHandler, IUnknown, <75AE0A2D-DC03-4C9F-8883-069660D0BEB6>
  COM_MTD_STD   Execute,                  :DWORD, :DWORD, :POINTER, :POINTER, :POINTER
  COM_MTD_STD   UpdateProperty,           :DWORD, :POINTER, :POINTER, :POINTER
COM_INTERFACE_END


;UI_COMMANDTYPE
UI_COMMANDTYPE_UNKNOWN            equ 0
UI_COMMANDTYPE_GROUP              equ 1
UI_COMMANDTYPE_ACTION             equ 2
UI_COMMANDTYPE_ANCHOR             equ 3
UI_COMMANDTYPE_CONTEXT            equ 4
UI_COMMANDTYPE_COLLECTION         equ 5
UI_COMMANDTYPE_COMMANDCOLLECTION  equ 6
UI_COMMANDTYPE_DECIMAL            equ 7
UI_COMMANDTYPE_BOOLEAN            equ 8
UI_COMMANDTYPE_FONT               equ 9
UI_COMMANDTYPE_RECENTITEMS        equ 10
UI_COMMANDTYPE_COLORANCHOR        equ 11
UI_COMMANDTYPE_COLORCOLLECTION    equ 12

;UI_VIEWTYPE
UI_VIEWTYPE_RIBBON                equ 1

;UI_VIEWVERB
UI_VIEWVERB_CREATE                equ 0
UI_VIEWVERB_DESTROY               equ 1
UI_VIEWVERB_SIZE                  equ 2
UI_VIEWVERB_ERROR                 equ 3

COM_INTERFACE_BEG IUIApplication, IUnknown, <D428903C-729A-491D-910D-682A08FF2522>
  COM_MTD_STD   OnViewChanged,            :DWORD, :DWORD, :POINTER, :DWORD, :DWORD
  COM_MTD_STD   OnCreateUICommand,        :DWORD, :DWORD, :POINTER
  COM_MTD_STD   OnDestroyUICommand,       :DWORD, :DWORD, :POINTER
COM_INTERFACE_END

COM_INTERFACE_BEG IUIImage, IUnknown, <23C8C838-4DE6-436B-AB01-5554BB7C30DD>
  COM_MTD_STD   GetBitmap,                :HBITMAP
COM_INTERFACE_END

;UI_OWNERSHIP
UI_OWNERSHIP_TRANSFER             equ 0
UI_OWNERSHIP_COPY                 equ 1

COM_INTERFACE_BEG IUIImageFromBitmap, IUnknown, <18ABA7F3-4C1C-4BA2-BF6C-F5C3326FA816>
  COM_MTD_STD   CreateImage,              :HBITMAP, :DWORD, :POINTER
COM_INTERFACE_END


sCLSID_UIRibbonFramework textequ <926749FA-2615-4987-8845-C33E65F2B957>
sCLSID_UIRibbonImageFromBitmapFactory textequ <0F7434B6-59B6-4250-999E-D168D6AE4293>
sLIBID_UIRibbon textequ <942F35C2-E83B-45EF-B085-AC295DD63D5B>
