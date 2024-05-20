;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\uxtheme.h
;             Created on (UTC) 06/04/2024 06:16:02
;             Last modified on (UTC) 21/02/2024 18:17:26

;---------------------------------------------------------------------------
ifndef _UXTHEME_H_
  _UXTHEME_H_ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    include commctrl.inc
    include SpecStrings.inc
    ifndef THEMEAPI
      if  not Defined(_UXTHEME_)
        THEMEAPI equ <EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE>
        THEMEAPI_ macro type_
          exitm <EXTERN_C DECLSPEC_IMPORT type_ STDAPICALLTYPE>
        endm
      else
        THEMEAPI equ <STDAPI>
        THEMEAPI_ macro type_
          exitm <STDAPI_(type_)>
        endm
        ;* _UXTHEME_ *
      endif
      ;* THEMEAPI *
    endif
    HTHEME typedef HANDLE
    ; handle to a section of theme data for class
    if (NTDDI_VERSION ge NTDDI_VISTA)
      MAX_THEMECOLOR equ 64
      MAX_THEMESIZE equ 64
    endif
    if (NTDDI_VERSION ge NTDDI_WIN7)
      ;---------------------------------------------------------------------------
      ; BeginPanningFeedback - Visual feedback init function related to pan gesture
      ;   - internally called by DefaultGestureHandler
      ;   - called by application
      ;  HWND hwnd - The handle to the Target window that will receive feedback
      ;                                                                                                 
      ;---------------------------------------------------------------------------
      @DefProto DllImport, BeginPanningFeedback, WIN_STD_CALL_CONV,, <:HWND>, 4
      ;---------------------------------------------------------------------------
      ; UpdatePanningFeedback : Visual feedback function related to pan gesture
      ; Can Be called only after a BeginPanningFeedback call 
      ;   - internally called by DefaultGestureHandler
      ;   - called by application
      ; HWND hwnd                 - The handle to the Target window that will receive feedback                                                
      ;                             For the method to succeed this must be the same hwnd as provided in 
      ;                             BeginPanningFeedback
      ;  
      ; LONG lTotalOverpanOffsetX - The Total displacement that the window has moved in the horizontal direction
      ;                             since the end of scrollable region was reached. The API would move the window by the distance specified                                                  
      ;                             A maximum displacement of 30 pixels is allowed
      ; LONG lTotalOverpanOffsetY - The Total displacement that the window has moved in the horizontal direction
      ;                             since the end of scrollable
      ;                             region was reached. The API would move the window by the distance specified                                                
      ;                             A maximum displacement of 30 pixels is allowed
      ;           
      ; BOOL fInInertia           - Flag dictating whether the Application is handling a WM_GESTURE message with the 
      ;                             GF_INERTIA FLAG set 
      ;   Incremental calls to UpdatePanningFeedback should make sure they always pass
      ;   the sum of the increments and not just the increment themselves
      ;   Eg : If the initial displacement is 10 pixels and the next displacement 10 pixels
      ;        the second call would be with the parameter as 20 pixels as opposed to 10
      ;   Eg : UpdatePanningFeedback(hwnd, 10, 10, TRUE)
      ; 
      @DefProto DllImport, UpdatePanningFeedback, WIN_STD_CALL_CONV,, <:HWND, :LONG, :LONG, :BOOL>, 16
      ;---------------------------------------------------------------------------
      ; EndPanningFeedback :Visual feedback reset function related to pan gesture
      ;   - internally called by DefaultGestureHandler
      ;   - called by application
      ;   Terminates any existing animation that was in process or set up by BeginPanningFeedback and UpdatePanningFeedback
      ;   The EndPanningFeedBack needs to be called Prior to calling any BeginPanningFeedBack if we have already
      ;   called a BeginPanningFeedBack followed by one/ more UpdatePanningFeedback calls
      ;  HWND hwnd         - The handle to the Target window that will receive feedback
      ;  BOOL fAnimateBack - Flag to indicate whether you wish the displaced window to move back
      ;                      to the original position via animation or a direct jump.
      ;                      Either ways the method will try to restore the moved window.
      ;                      The latter case exists for compatibility with legacy apps. 
      @DefProto DllImport, EndPanningFeedback, WIN_STD_CALL_CONV,, <:HWND, :BOOL>, 8
    endif
    if (NTDDI_VERSION ge NTDDI_WIN8)
      ;---------------------------------------------------------------------------
      ;  Theme animation properties
      TA_PROPERTY typedef SDWORD
      TAP_FLAGS equ 0
      TAP_TRANSFORMCOUNT equ 1
      TAP_STAGGERDELAY equ 2
      TAP_STAGGERDELAYCAP equ 3
      TAP_STAGGERDELAYFACTOR equ 4
      TAP_ZORDER equ 5

      ;---------------------------------------------------------------------------
      ;  when dwProperty is TAP_FLAGS, GetThemeAnimationProperty returns
      ;  a combination of the following values
      TA_PROPERTY_FLAG typedef SDWORD
      TAPF_NONE equ 0h
      TAPF_HASSTAGGER equ 1h
      TAPF_ISRTLAWARE equ 2h
      TAPF_ALLOWCOLLECTION equ 4h
      TAPF_HASBACKGROUND equ 8h
      TAPF_HASPERSPECTIVE equ 10h

      DEFINE_ENUM_FLAG_OPERATORS(TA_PROPERTY_FLAG)
      ;---------------------------------------------------------------------------
      ;  GetThemeAnimationProperty() - Retrieve a theme animation property based
      ;                                on the storybard id and the target id.
      ;                                Storyboard id and target id is defined in vsanimation.h
      ;                                Available properties are defined above, 
      ;                                with prefix TAP_.
      ;  hTheme                      - Theme data handle (from OpenThemeData API)
      ;  
      ;  iStoryboardId               - Animation storyboard identifier
      ;  iTargetId                   - Target surface identifier
      ;  eProperty                   - Property associated with the animation storyboard and target
      ;  pvProperty                  - Buffer to receive returned property value
      ;  cbSize                      - Byte size of a buffer pointed by pvProperty
      ;  pcbSizeOut                  - pointer to a DWORD buffer to receive the returned 
      ;                                byte size
      @DefProto DllImport, GetThemeAnimationProperty, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :TA_PROPERTY, :ptr VOID, :DWORD, :ptr DWORD>, 28
      ;---------------------------------------------------------------------------
      ;  Theme animation transform types
      TA_TRANSFORM_TYPE typedef SDWORD
      TATT_TRANSLATE_2D equ 0
      TATT_SCALE_2D equ 1
      TATT_OPACITY equ 2
      TATT_CLIP equ 3

      ;---------------------------------------------------------------------------
      ;  Theme animation transform flags
      TA_TRANSFORM_FLAG typedef SDWORD
      TATF_NONE equ 0h
      TATF_TARGETVALUES_USER equ 1h
      TATF_HASINITIALVALUES equ 2h
      TATF_HASORIGINVALUES equ 4h

      DEFINE_ENUM_FLAG_OPERATORS(TA_TRANSFORM_FLAG)
      include pshpack8.inc
      TA_TRANSFORM struct
        eTransformType TA_TRANSFORM_TYPE ?
        dwTimingFunctionId DWORD ?
        dwStartTime DWORD ?
        ; in milliseconds
        dwDurationTime DWORD ?
        eFlags_ TA_TRANSFORM_FLAG ?
      TA_TRANSFORM ends
      PTA_TRANSFORM typedef ptr TA_TRANSFORM
      TA_TRANSFORM_2D struct
        header TA_TRANSFORM <>
        rX REAL4 ?
        rY REAL4 ?
        rInitialX REAL4 ?
        rInitialY REAL4 ?
        rOriginX REAL4 ?
        rOriginY REAL4 ?
      TA_TRANSFORM_2D ends
      PTA_TRANSFORM_2D typedef ptr TA_TRANSFORM_2D
      TA_TRANSFORM_OPACITY struct
        header TA_TRANSFORM <>
        rOpacity REAL4 ?
        rInitialOpacity REAL4 ?
      TA_TRANSFORM_OPACITY ends
      PTA_TRANSFORM_OPACITY typedef ptr TA_TRANSFORM_OPACITY
      TA_TRANSFORM_CLIP struct
        header TA_TRANSFORM <>
        rLeft REAL4 ?
        rTop REAL4 ?
        rRight REAL4 ?
        rBottom REAL4 ?
        rInitialLeft REAL4 ?
        rInitialTop REAL4 ?
        rInitialRight REAL4 ?
        rInitialBottom REAL4 ?
      TA_TRANSFORM_CLIP ends
      PTA_TRANSFORM_CLIP typedef ptr TA_TRANSFORM_CLIP
      include poppack.inc
      ;---------------------------------------------------------------------------
      ;  GetThemeAnimationTransform()    - Retrieve an animation transform operation
      ;                                    based on storyboard id, target id and transform
      ;                                    index
      ;                                    Transform index is in the range of (0, dwTransformCount - 1).
      ;                                    dwTransformCount can be retrieved by calling
      ;                                    GetThemeAnimationProperty with TAP_TRANSFORMCOUNT
      ;  hTheme                          - Opened theme handle
      ;  iStoryboardId                   - A predefined storyboard identifier
      ;  iTargetId                       - A predefined target identifier
      ;  dwTransformIndex                - Zero-based index of a transform operation
      ;  pTransform                      - Pointer buffer to receive a transform structure
      ;  pcbSizeOut                      - pointer to a DWORD buffer to receive returned
      ;                                    byte-size of transform operation struct
      @DefProto DllImport, GetThemeAnimationTransform, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :DWORD, :ptr TA_TRANSFORM, :DWORD, :ptr DWORD>, 28
      ;---------------------------------------------------------------------------
      ;  Timing function type
      TA_TIMINGFUNCTION_TYPE typedef SDWORD
      TTFT_UNDEFINED equ 0
      TTFT_CUBIC_BEZIER equ 1

      include pshpack8.inc
      TA_TIMINGFUNCTION struct
        eTimingFunctionType TA_TIMINGFUNCTION_TYPE ?
      TA_TIMINGFUNCTION ends
      PTA_TIMINGFUNCTION typedef ptr TA_TIMINGFUNCTION
      TA_CUBIC_BEZIER struct
        header TA_TIMINGFUNCTION <>
        rX0 REAL4 ?
        rY0 REAL4 ?
        rX1 REAL4 ?
        rY1 REAL4 ?
      TA_CUBIC_BEZIER ends
      PTA_CUBIC_BEZIER typedef ptr TA_CUBIC_BEZIER
      include poppack.inc
      ;---------------------------------------------------------------------------
      ;  GetThemeTimingFunction          - Retrieve a predefined timing function based on
      ;                                    a timing function identifier
      ;  hTheme                          - Opened theme handle
      ;  iTimingFunctionId               - Timing function identifier
      ;  ppThemeTimingFunction           - Buffer to receive a pre-defined timing function pointer
      ;  pcbSizeOut                      - pointer to a DWORD buffer to receive byte-size of
      ;                                    the timing function struct
      ;                                      
      @DefProto DllImport, GetThemeTimingFunction, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :ptr TA_TIMINGFUNCTION, :DWORD, :ptr DWORD>, 20
      ;* NTDDI_WIN8 *
    endif
    ;---------------------------------------------------------------------------
    ; NOTE: PartId's and StateId's used in the theme API are defined in the 
    ;       hdr file <vssym32.h> using the TM_PART and TM_STATE macros.  For
    ;       example, "TM_PART(BP, PUSHBUTTON)" defines the PartId "BP_PUSHBUTTON".
    ;---------------------------------------------------------------------------
    ;  OpenThemeData()     - Open the theme data for the specified HWND and 
    ;                        semi-colon separated list of class names. 
    ; 
    ;                        OpenThemeData() will try each class name, one at 
    ;                        a time, and use the first matching theme info
    ;                        found.  If a match is found, a theme handle
    ;                        to the data is returned.  If no match is found,
    ;                        a "NULL" handle is returned. 
    ;                        When the window is destroyed or a WM_THEMECHANGED
    ;                        msg is received, "CloseThemeData()" should be 
    ;                        called to close the theme handle.
    ;  hwnd                - window handle of the control/window to be themed
    ;  pszClassList        - class name (or list of names) to match to theme data
    ;                        section.  if the list contains more than one name, 
    ;                        the names are tested one at a time for a match.  
    ;                        If a match is found, OpenThemeData() returns a 
    ;                        theme handle associated with the matching class. 
    ;                        This param is a list (instead of just a single 
    ;                        class name) to provide the class an opportunity 
    ;                        to get the "best" match between the class and 
    ;                        the current theme.  For example, a button might
    ;                        pass L"OkButton, Button" if its ID=ID_OK.  If 
    ;                        the current theme has an entry for OkButton, 
    ;                        that will be used.  Otherwise, we fall back on 
    ;                        the normal Button entry.
    ;---------------------------------------------------------------------------
    @DefProto DllImport, OpenThemeData, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR>, 8
    OTD_FORCE_RECT_SIZING equ 00000001h; make all parts size to rect

    OTD_NONCLIENT equ 00000002h; set if hTheme to be used for nonclient area

    OTD_VALIDBITS equ <(OTD_FORCE_RECT_SIZING or OTD_NONCLIENT)>
    @DefProto DllImport, OpenThemeDataForDpi, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR, :UINT>, 12
    ;---------------------------------------------------------------------------
    ;  OpenThemeDataEx     - Open the theme data for the specified HWND and 
    ;                        semi-colon separated list of class names. 
    ; 
    ;                        OpenThemeData() will try each class name, one at 
    ;                        a time, and use the first matching theme info
    ;                        found.  If a match is found, a theme handle
    ;                        to the data is returned.  If no match is found,
    ;                        a "NULL" handle is returned. 
    ;                        When the window is destroyed or a WM_THEMECHANGED
    ;                        msg is received, "CloseThemeData()" should be 
    ;                        called to close the theme handle.
    ;  hwnd                - window handle of the control/window to be themed
    ;  pszClassList        - class name (or list of names) to match to theme data
    ;                        section.  if the list contains more than one name, 
    ;                        the names are tested one at a time for a match.  
    ;                        If a match is found, OpenThemeData() returns a 
    ;                        theme handle associated with the matching class. 
    ;                        This param is a list (instead of just a single 
    ;                        class name) to provide the class an opportunity 
    ;                        to get the "best" match between the class and 
    ;                        the current theme.  For example, a button might
    ;                        pass L"OkButton, Button" if its ID=ID_OK.  If 
    ;                        the current theme has an entry for OkButton, 
    ;                        that will be used.  Otherwise, we fall back on 
    ;                        the normal Button entry.
    ;  dwFlags              - allows certain overrides of std features
    ;                         (see OTD_XXX defines above)
    ;---------------------------------------------------------------------------
    @DefProto DllImport, OpenThemeDataEx, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR, :DWORD>, 12
    ;---------------------------------------------------------------------------
    ;  CloseThemeData()    - closes the theme data handle.  This should be done 
    ;                        when the window being themed is destroyed or
    ;                        whenever a WM_THEMECHANGED msg is received 
    ;                        (followed by an attempt to create a new Theme data 
    ;                        handle).
    ;  hTheme              - open theme data handle (returned from prior call
    ;                        to OpenThemeData() API).
    ;---------------------------------------------------------------------------
    @DefProto DllImport, CloseThemeData, WIN_STD_CALL_CONV,, <:HTHEME>, 4
    ;---------------------------------------------------------------------------
    ;    functions for basic drawing support 
    ;---------------------------------------------------------------------------
    ; The following methods are the theme-aware drawing services.
    ; Controls/Windows are defined in drawable "parts" by their author: a 
    ; parent part and 0 or more child parts.  Each of the parts can be 
    ; described in "states" (ex: disabled, hot, pressed).  
    ;---------------------------------------------------------------------------
    ; For the list of all themed classes and the definition of all
    ; parts and states, see the file "tmschmea.h".
    ;---------------------------------------------------------------------------
    ; Each of the below methods takes a "iPartId" param to specify the 
    ; part and a "iStateId" to specify the state of the part.  
    ; "iStateId=0" refers to the root part.  "iPartId" = "0" refers to 
    ; the root class.  
    ;-----------------------------------------------------------------------
    ; Note: draw operations are always scaled to fit (and not to exceed)  
    ; the specified "Rect".
    ;-----------------------------------------------------------------------
    ;------------------------------------------------------------------------
    ;  DrawThemeBackground()   
    ;                      - draws the theme-specified border and fill for 
    ;                        the "iPartId" and "iStateId".  This could be 
    ;                        based on a bitmap file, a border and fill, or 
    ;                        other image description.  
    ;  hTheme              - theme data handle
    ;  hdc                 - HDC to draw into
    ;  iPartId             - part number to draw
    ;  iStateId            - state number (of the part) to draw
    ;  pRect               - defines the size/location of the part
    ;  pClipRect           - optional clipping rect (don't draw outside it)
    ;------------------------------------------------------------------------
    @DefProto DllImport, DrawThemeBackground, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :LPCRECT, :LPCRECT>, 24
    ;------------------------------------------------------------------------
    ;---- bits used in dwFlags of DTBGOPTS ----
    DTBG_CLIPRECT equ 00000001h; rcClip has been specified

    DTBG_DRAWSOLID equ 00000002h; DEPRECATED: draw transparent/alpha images as solid

    DTBG_OMITBORDER equ 00000004h; don't draw border of part

    DTBG_OMITCONTENT equ 00000008h; don't draw content area of part

    DTBG_COMPUTINGREGION equ 00000010h; TRUE if calling to compute region

    DTBG_MIRRORDC equ 00000020h; assume the hdc is mirrorred and

    ; flip images as appropriate (currently 
    ; only supported for bgtype=imagefile)
    DTBG_NOMIRROR equ 00000040h; don't mirror the output, overrides everything else 

    DTBG_VALIDBITS equ <(DTBG_CLIPRECT or DTBG_DRAWSOLID or DTBG_OMITBORDER or DTBG_OMITCONTENT or DTBG_COMPUTINGREGION or DTBG_MIRRORDC or DTBG_NOMIRROR)>
    DTBGOPTS struct
      dwSize DWORD ?
      ; size of the struct
      dwFlags DWORD ?
      ; which options have been specified
      rcClip RECT <>
      ; clipping rectangle
    DTBGOPTS ends
    _DTBGOPTS typedef DTBGOPTS
    PDTBGOPTS typedef ptr DTBGOPTS
    ;------------------------------------------------------------------------
    ;  DrawThemeBackgroundEx()   
    ;                      - draws the theme-specified border and fill for 
    ;                        the "iPartId" and "iStateId".  This could be 
    ;                        based on a bitmap file, a border and fill, or 
    ;                        other image description.  NOTE: This will be
    ;                        merged back into DrawThemeBackground() after 
    ;                        BETA 2.
    ;  hTheme              - theme data handle
    ;  hdc                 - HDC to draw into
    ;  iPartId             - part number to draw
    ;  iStateId            - state number (of the part) to draw
    ;  pRect               - defines the size/location of the part
    ;  pOptions            - ptr to optional params
    ;------------------------------------------------------------------------
    @DefProto DllImport, DrawThemeBackgroundEx, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :LPCRECT, :ptr DTBGOPTS>, 24
    ;---------------------------------------------------------------------------
    ;----- DrawThemeText() flags ----
    DTT_GRAYED equ 00000001h; draw a grayed-out string (this is deprecated)

    DTT_FLAGS2VALIDBITS equ <(DTT_GRAYED)>
    ;-------------------------------------------------------------------------
    ;  DrawThemeText()     - draws the text using the theme-specified 
    ;                        color and font for the "iPartId" and 
    ;                        "iStateId".  
    ;  hTheme              - theme data handle
    ;  hdc                 - HDC to draw into
    ;  iPartId             - part number to draw
    ;  iStateId            - state number (of the part) to draw
    ;  pszText             - actual text to draw
    ;  dwCharCount         - number of chars to draw (-1 for all)
    ;  dwTextFlags         - same as DrawText() "uFormat" param
    ;  dwTextFlags2        - additional drawing options 
    ;  pRect               - defines the size/location of the part
    ;-------------------------------------------------------------------------
    @DefProto DllImport, DrawThemeText, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :LPCWSTR, :SDWORD, :DWORD, :DWORD, :LPCRECT>, 36
    ;-------------------------------------------------------------------------
    ;  GetThemeBackgroundContentRect()
    ;                      - gets the size of the content for the theme-defined 
    ;                        background.  This is usually the area inside
    ;                        the borders or Margins.  
    ;      hTheme          - theme data handle
    ;      hdc             - (optional) device content to be used for drawing
    ;      iPartId         - part number to draw
    ;      iStateId        - state number (of the part) to draw
    ;      pBoundingRect   - the outer RECT of the part being drawn
    ;      pContentRect    - RECT to receive the content area
    ;-------------------------------------------------------------------------
    @DefProto DllImport, GetThemeBackgroundContentRect, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :LPCRECT, :LPRECT>, 24
    ;-------------------------------------------------------------------------
    ;  GetThemeBackgroundExtent() - calculates the size/location of the theme-
    ;                               specified background based on the 
    ;                               "pContentRect".
    ;      hTheme          - theme data handle
    ;      hdc             - (optional) device content to be used for drawing
    ;      iPartId         - part number to draw
    ;      iStateId        - state number (of the part) to draw
    ;      pContentRect    - RECT that defines the content area
    ;      pBoundingRect   - RECT to receive the overall size/location of part
    ;-------------------------------------------------------------------------
    @DefProto DllImport, GetThemeBackgroundExtent, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :LPCRECT, :LPRECT>, 24
    ;-------------------------------------------------------------------------
    ;  GetThemeBackgroundRegion()
    ;                      - computes the region for a regular or partially 
    ;                        transparent theme-specified background that is 
    ;                        bound by the specified "pRect".
    ;                        If the rectangle is empty, sets the HRGN to NULL 
    ;                        and return S_FALSE.
    ;  hTheme              - theme data handle
    ;  hdc                 - optional HDC to draw into (DPI scaling)
    ;  iPartId             - part number to draw
    ;  iStateId            - state number (of the part) 
    ;  pRect               - the RECT used to draw the part
    ;  pRegion             - receives handle to calculated region
    ;-------------------------------------------------------------------------
    @DefProto DllImport, GetThemeBackgroundRegion, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :LPCRECT, :ptr HRGN>, 24
    THEMESIZE typedef SDWORD
    TS_MIN equ 0
    ; minimum size
    TS_TRUE equ 1
    ; size without stretching
    TS_DRAW equ 2

    ; size that theme mgr will use to draw part
    ;-------------------------------------------------------------------------
    ;  GetThemePartSize() - returns the specified size of the theme part
    ;  hTheme              - theme data handle
    ;  hdc                 - HDC to select font into & measure against
    ;  iPartId             - part number to retrieve size for
    ;  iStateId            - state number (of the part) 
    ;  prc                 - (optional) rect for part drawing destination
    ;  eSize               - the type of size to be retreived
    ;  psz                 - receives the specified size of the part 
    ;-------------------------------------------------------------------------
    @DefProto DllImport, GetThemePartSize, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :LPCRECT, :THEMESIZE, :ptr SIZE_>, 28
    ;-------------------------------------------------------------------------
    ;  GetThemeTextExtent() - calculates the size/location of the specified 
    ;                         text when rendered in the Theme Font. 
    ;  hTheme              - theme data handle
    ;  hdc                 - HDC to select font & measure into
    ;  iPartId             - part number to draw
    ;  iStateId            - state number (of the part) 
    ;  pszText             - the text to be measured
    ;  dwCharCount         - number of chars to draw (-1 for all)
    ;  dwTextFlags         - same as DrawText() "uFormat" param
    ;  pszBoundingRect     - optional: to control layout of text
    ;  pszExtentRect       - receives the RECT for text size/location
    ;-------------------------------------------------------------------------
    @DefProto DllImport, GetThemeTextExtent, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :LPCWSTR, :SDWORD, :DWORD, :LPCRECT, :LPRECT>, 36
    ;-------------------------------------------------------------------------
    ;  GetThemeTextMetrics()
    ;                      - returns info about the theme-specified font
    ;                        for the part/state passed in.
    ;  hTheme              - theme data handle
    ;  hdc                 - optional: HDC for screen context
    ;  iPartId             - part number to draw
    ;  iStateId            - state number (of the part) 
    ;  ptm                 - receives the font info
    ;-------------------------------------------------------------------------
    @DefProto DllImport, GetThemeTextMetrics, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :ptr TEXTMETRICW>, 20
    ;-------------------------------------------------------------------------
    ;----- HitTestThemeBackground, HitTestThemeBackgroundRegion flags ----
    ;  Theme background segment hit test flag (default). possible return values are:
    ;  HTCLIENT: hit test succeeded in the middle background segment
    ;  HTTOP, HTLEFT, HTTOPLEFT, etc:  // hit test succeeded in the the respective theme background segment.
    HTTB_BACKGROUNDSEG equ 00000000h
    ;  Fixed border hit test option.  possible return values are:
    ;  HTCLIENT: hit test succeeded in the middle background segment
    ;  HTBORDER: hit test succeeded in any other background segment
    HTTB_FIXEDBORDER equ 00000002h; Return code may be either HTCLIENT or HTBORDER. 

    ;  Caption hit test option.  Possible return values are:
    ;  HTCAPTION: hit test succeeded in the top, top left, or top right background segments
    ;  HTNOWHERE or another return code, depending on absence or presence of accompanying flags, resp.
    HTTB_CAPTION equ 00000004h
    ;  Resizing border hit test flags.  Possible return values are:
    ;  HTCLIENT: hit test succeeded in middle background segment
    ;  HTTOP, HTTOPLEFT, HTLEFT, HTRIGHT, etc:    hit test succeeded in the respective system resizing zone
    ;  HTBORDER: hit test failed in middle segment and resizing zones, but succeeded in a background border segment
    HTTB_RESIZINGBORDER_LEFT equ 00000010h; Hit test left resizing border, 

    HTTB_RESIZINGBORDER_TOP equ 00000020h; Hit test top resizing border

    HTTB_RESIZINGBORDER_RIGHT equ 00000040h; Hit test right resizing border

    HTTB_RESIZINGBORDER_BOTTOM equ 00000080h; Hit test bottom resizing border

    HTTB_RESIZINGBORDER equ <(HTTB_RESIZINGBORDER_LEFT or HTTB_RESIZINGBORDER_TOP or HTTB_RESIZINGBORDER_RIGHT or HTTB_RESIZINGBORDER_BOTTOM)>
    ; Resizing border is specified as a template, not just window edges.
    ; This option is mutually exclusive with HTTB_SYSTEMSIZINGWIDTH; HTTB_SIZINGTEMPLATE takes precedence  
    HTTB_SIZINGTEMPLATE equ 00000100h
    ; Use system resizing border width rather than theme content margins.   
    ; This option is mutually exclusive with HTTB_SIZINGTEMPLATE, which takes precedence.
    HTTB_SYSTEMSIZINGMARGINS equ 00000200h
    ;-------------------------------------------------------------------------
    ;  HitTestThemeBackground()
    ;                      - returns a HitTestCode (a subset of the values 
    ;                        returned by WM_NCHITTEST) for the point "ptTest" 
    ;                        within the theme-specified background
    ;                        (bound by pRect).  "pRect" and "ptTest" should 
    ;                        both be in the same coordinate system 
    ;                        (client, screen, etc).
    ;      hTheme          - theme data handle
    ;      hdc             - HDC to draw into
    ;      iPartId         - part number to test against
    ;      iStateId        - state number (of the part) 
    ;      pRect           - the RECT used to draw the part
    ;      hrgn            - optional region to use; must be in same coordinates as
    ;                      -    pRect and pTest.
    ;      ptTest          - the hit point to be tested
    ;      dwOptions       - HTTB_xxx constants
    ;      pwHitTestCode   - receives the returned hit test code - one of:
    ;  
    ;                        HTNOWHERE, HTLEFT, HTTOPLEFT, HTBOTTOMLEFT,
    ;                        HTRIGHT, HTTOPRIGHT, HTBOTTOMRIGHT,
    ;                        HTTOP, HTBOTTOM, HTCLIENT
    ;-------------------------------------------------------------------------
    @DefProto DllImport, HitTestThemeBackground, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :DWORD, :LPCRECT, :HRGN, :POINT, :ptr WORD>, 36
    ;------------------------------------------------------------------------
    ;  DrawThemeEdge()     - Similar to the DrawEdge() API, but uses part colors
    ;                        and is high-DPI aware
    ;  hTheme              - theme data handle
    ;  hdc                 - HDC to draw into
    ;  iPartId             - part number to draw
    ;  iStateId            - state number of part
    ;  pDestRect           - the RECT used to draw the line(s)
    ;  uEdge               - Same as DrawEdge() API
    ;  uFlags              - Same as DrawEdge() API
    ;  pContentRect        - Receives the interior rect if (uFlags & BF_ADJUST)
    ;------------------------------------------------------------------------
    @DefProto DllImport, DrawThemeEdge, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :LPCRECT, :UINT, :UINT, :LPRECT>, 32
    ;------------------------------------------------------------------------
    ;  DrawThemeIcon()     - draws an image within an imagelist based on 
    ;                        a (possible) theme-defined effect. 
    ;  hTheme              - theme data handle
    ;  hdc                 - HDC to draw into
    ;  iPartId             - part number to draw
    ;  iStateId            - state number of part
    ;  pRect               - the RECT to draw the image within
    ;  himl                - handle to IMAGELIST 
    ;  iImageIndex         - index into IMAGELIST (which icon to draw)
    ;------------------------------------------------------------------------
    @DefProto DllImport, DrawThemeIcon, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :LPCRECT, :HIMAGELIST, :SDWORD>, 28
    ;---------------------------------------------------------------------------
    ;  IsThemePartDefined() - returns TRUE if the theme has defined parameters
    ;                         for the specified "iPartId" and "iStateId".
    ;  hTheme              - theme data handle
    ;  iPartId             - part number to find definition for
    ;  iStateId            - state number of part
    ;---------------------------------------------------------------------------
    @DefProto DllImport, IsThemePartDefined, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD>, 12
    ;---------------------------------------------------------------------------
    ;  IsThemeBackgroundPartiallyTransparent()
    ;                      - returns TRUE if the theme specified background for 
    ;                        the part/state has transparent pieces or 
    ;                        alpha-blended pieces.
    ;  hTheme              - theme data handle
    ;  iPartId             - part number 
    ;  iStateId            - state number of part
    ;---------------------------------------------------------------------------
    @DefProto DllImport, IsThemeBackgroundPartiallyTransparent, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD>, 12
    ;---------------------------------------------------------------------------
    ;    lower-level theme information services
    ;---------------------------------------------------------------------------
    ; The following methods are getter routines for each of the Theme Data types.
    ; Controls/Windows are defined in drawable "parts" by their author: a 
    ; parent part and 0 or more child parts.  Each of the parts can be 
    ; described in "states" (ex: disabled, hot, pressed).  
    ;---------------------------------------------------------------------------
    ; Each of the below methods takes a "iPartId" param to specify the 
    ; part and a "iStateId" to specify the state of the part.  
    ; "iStateId=0" refers to the root part.  "iPartId" = "0" refers to 
    ; the root class.  
    ;-----------------------------------------------------------------------
    ; Each method also take a "iPropId" param because multiple instances of 
    ; the same primitive type can be defined in the theme schema.
    ;-----------------------------------------------------------------------
    ;-----------------------------------------------------------------------
    ;  GetThemeColor()     - Get the value for the specified COLOR property
    ;  hTheme              - theme data handle
    ;  iPartId             - part number 
    ;  iStateId            - state number of part
    ;  iPropId             - the property number to get the value for
    ;  pColor              - receives the value of the property
    ;-----------------------------------------------------------------------
    @DefProto DllImport, GetThemeColor, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :ptr COLORREF>, 20
    ;-----------------------------------------------------------------------
    ;  GetThemeMetric()    - Get the value for the specified metric/size
    ;                        property
    ;  hTheme              - theme data handle
    ;  hdc                 - (optional) hdc to be drawn into (DPI scaling)
    ;  iPartId             - part number 
    ;  iStateId            - state number of part
    ;  iPropId             - the property number to get the value for
    ;  piVal               - receives the value of the property
    ;-----------------------------------------------------------------------
    @DefProto DllImport, GetThemeMetric, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :SDWORD, :ptr SDWORD>, 24
    ;-----------------------------------------------------------------------
    ;  GetThemeString()    - Get the value for the specified string property
    ;  hTheme              - theme data handle
    ;  iPartId             - part number 
    ;  iStateId            - state number of part
    ;  iPropId             - the property number to get the value for
    ;  pszBuff             - receives the string property value
    ;  cchMaxBuffChars     - max. number of chars allowed in pszBuff
    ;-----------------------------------------------------------------------
    @DefProto DllImport, GetThemeString, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :LPWSTR, :SDWORD>, 24
    ;-----------------------------------------------------------------------
    ;  GetThemeBool()      - Get the value for the specified BOOL property
    ;  hTheme              - theme data handle
    ;  iPartId             - part number 
    ;  iStateId            - state number of part
    ;  iPropId             - the property number to get the value for
    ;  pfVal               - receives the value of the property
    ;-----------------------------------------------------------------------
    @DefProto DllImport, GetThemeBool, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :ptr BOOL>, 20
    ;-----------------------------------------------------------------------
    ;  GetThemeInt()       - Get the value for the specified int property
    ;  hTheme              - theme data handle
    ;  iPartId             - part number 
    ;  iStateId            - state number of part
    ;  iPropId             - the property number to get the value for
    ;  piVal               - receives the value of the property
    ;-----------------------------------------------------------------------
    @DefProto DllImport, GetThemeInt, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :ptr SDWORD>, 20
    ;-----------------------------------------------------------------------
    ;  GetThemeEnumValue() - Get the value for the specified ENUM property
    ;  hTheme              - theme data handle
    ;  iPartId             - part number 
    ;  iStateId            - state number of part
    ;  iPropId             - the property number to get the value for
    ;  piVal               - receives the value of the enum (cast to int*)
    ;-----------------------------------------------------------------------
    @DefProto DllImport, GetThemeEnumValue, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :ptr SDWORD>, 20
    ;-----------------------------------------------------------------------
    ;  GetThemePosition()  - Get the value for the specified position
    ;                        property
    ;  hTheme              - theme data handle
    ;  iPartId             - part number 
    ;  iStateId            - state number of part
    ;  iPropId             - the property number to get the value for
    ;  pPoint              - receives the value of the position property
    ;-----------------------------------------------------------------------
    @DefProto DllImport, GetThemePosition, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :ptr POINT>, 20
    ;-----------------------------------------------------------------------
    ;  GetThemeFont()      - Get the value for the specified font property
    ;  hTheme              - theme data handle
    ;  hdc                 - (optional) hdc to be drawn to (DPI scaling)
    ;  iPartId             - part number 
    ;  iStateId            - state number of part
    ;  iPropId             - the property number to get the value for
    ;  pFont               - receives the value of the LOGFONT property
    ;                        (scaled for the current logical screen dpi) 
    ;-----------------------------------------------------------------------
    @DefProto DllImport, GetThemeFont, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :SDWORD, :ptr LOGFONTW>, 24
    ;-----------------------------------------------------------------------
    ;  GetThemeRect()      - Get the value for the specified RECT property
    ;  hTheme              - theme data handle
    ;  iPartId             - part number 
    ;  iStateId            - state number of part
    ;  iPropId             - the property number to get the value for
    ;  pRect               - receives the value of the RECT property
    ;-----------------------------------------------------------------------
    @DefProto DllImport, GetThemeRect, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :LPRECT>, 20
    MARGINS struct
      cxLeftWidth SDWORD ?
      ; width of left border that retains its size
      cxRightWidth SDWORD ?
      ; width of right border that retains its size
      cyTopHeight SDWORD ?
      ; height of top border that retains its size
      cyBottomHeight SDWORD ?
      ; height of bottom border that retains its size
    MARGINS ends
    _MARGINS typedef MARGINS
    PMARGINS typedef ptr MARGINS
    ;-----------------------------------------------------------------------
    ;  GetThemeMargins()   - Get the value for the specified MARGINS property
    ;      hTheme          - theme data handle
    ;      hdc             - (optional) hdc to be used for drawing
    ;      iPartId         - part number 
    ;      iStateId        - state number of part
    ;      iPropId         - the property number to get the value for
    ;      prc             - RECT for area to be drawn into
    ;      pMargins        - receives the value of the MARGINS property
    ;-----------------------------------------------------------------------
    @DefProto DllImport, GetThemeMargins, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :SDWORD, :LPCRECT, :ptr MARGINS>, 28
    if (NTDDI_VERSION ge NTDDI_VISTA)
      MAX_INTLIST_COUNT equ 402
    else
      MAX_INTLIST_COUNT equ 10
    endif
    INTLIST struct
      iValueCount SDWORD ?
      ; number of values in iValues
      iValues SDWORD MAX_INTLIST_COUNT dup (?)
    INTLIST ends
    _INTLIST typedef INTLIST
    PINTLIST typedef ptr INTLIST
    ;-----------------------------------------------------------------------
    ;  GetThemeIntList()   - Get the value for the specified INTLIST struct
    ;      hTheme          - theme data handle
    ;      iPartId         - part number 
    ;      iStateId        - state number of part
    ;      iPropId         - the property number to get the value for
    ;      pIntList        - receives the value of the INTLIST property
    ;-----------------------------------------------------------------------
    @DefProto DllImport, GetThemeIntList, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :ptr INTLIST>, 20
    PROPERTYORIGIN typedef SDWORD
    PO_STATE equ 0
    ; property was found in the state section
    PO_PART equ 1
    ; property was found in the part section
    PO_CLASS equ 2
    ; property was found in the class section
    PO_GLOBAL equ 3
    ; property was found in [globals] section
    PO_NOTFOUND equ 4

    ; property was not found
    ;-----------------------------------------------------------------------
    ;  GetThemePropertyOrigin()
    ;                      - searches for the specified theme property
    ;                        and sets "pOrigin" to indicate where it was 
    ;                        found (or not found)
    ;  hTheme              - theme data handle
    ;  iPartId             - part number 
    ;  iStateId            - state number of part
    ;  iPropId             - the property number to search for
    ;  pOrigin             - receives the value of the property origin
    ;-----------------------------------------------------------------------
    @DefProto DllImport, GetThemePropertyOrigin, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :ptr PROPERTYORIGIN>, 20
    ;---------------------------------------------------------------------------
    ;  SetWindowTheme()
    ;                      - redirects an existing Window to use a different 
    ;                        section of the current theme information than its 
    ;                        class normally asks for.
    ;  hwnd                - the handle of the window (cannot be NULL)
    ;  pszSubAppName       - app (group) name to use in place of the calling
    ;                        app's name.  If NULL, the actual calling app 
    ;                        name will be used.
    ;  pszSubIdList        - semicolon separated list of class Id names to 
    ;                        use in place of actual list passed by the 
    ;                        window's class.  if NULL, the id list from the 
    ;                        calling class is used.
    ;---------------------------------------------------------------------------
    ; The Theme Manager will remember the "pszSubAppName" and the
    ; "pszSubIdList" associations thru the lifetime of the window (even 
    ; if themes are subsequently changed).  The window is sent a 
    ; "WM_THEMECHANGED" msg at the end of this call, so that the new
    ; theme can be found and applied.
    ;---------------------------------------------------------------------------
    ; When "pszSubAppName" or "pszSubIdList" are NULL, the Theme Manager 
    ; removes the previously remember association.  To turn off theme-ing for 
    ; the specified window, you can pass an empty string (L"") so it 
    ; won't match any section entries.
    ;---------------------------------------------------------------------------
    @DefProto DllImport, SetWindowTheme, WIN_STD_CALL_CONV,, <:HWND, :LPCWSTR, :LPCWSTR>, 12
    ;---------------------------------------------------------------------------
    ;  GetThemeFilename()  - Get the value for the specified FILENAME property.
    ;  hTheme              - theme data handle
    ;  iPartId             - part number 
    ;  iStateId            - state number of part
    ;  iPropId             - the property number to search for
    ;  pszThemeFileName    - output buffer to receive the filename
    ;  cchMaxBuffChars     - the size of the return buffer, in chars
    ;---------------------------------------------------------------------------
    @DefProto DllImport, GetThemeFilename, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :LPWSTR, :SDWORD>, 24
    ;---------------------------------------------------------------------------
    ;  GetThemeSysColor()  - Get the value of the specified System color. 
    ;  hTheme              - the theme data handle.  if non-NULL, will return
    ;                        color from [SysMetrics] section of theme.
    ;                        if NULL, will return the global system color.
    ;  iColorId            - the system color index defined in winuser.h
    ;---------------------------------------------------------------------------
    @DefProto DllImport, GetThemeSysColor, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD>, 8
    ;---------------------------------------------------------------------------
    ;  GetThemeSysColorBrush() 
    ;                      - Get the brush for the specified System color. 
    ;  hTheme              - the theme data handle.  if non-NULL, will return
    ;                        brush matching color from [SysMetrics] section of 
    ;                        theme.  if NULL, will return the brush matching
    ;                        global system color.
    ;  iColorId            - the system color index defined in winuser.h
    ;---------------------------------------------------------------------------
    @DefProto DllImport, GetThemeSysColorBrush, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD>, 8
    ;---------------------------------------------------------------------------
    ;  GetThemeSysBool()   - Get the boolean value of specified System metric. 
    ;  hTheme              - the theme data handle.  if non-NULL, will return
    ;                        BOOL from [SysMetrics] section of theme.
    ;                        if NULL, will return the specified system boolean.
    ;  iBoolId             - the TMT_XXX BOOL number (first BOOL
    ;                        is TMT_FLATMENUS)
    ;---------------------------------------------------------------------------
    @DefProto DllImport, GetThemeSysBool, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD>, 8
    ;---------------------------------------------------------------------------
    ;  GetThemeSysSize()   - Get the value of the specified System size metric. 
    ;                        (scaled for the current logical screen dpi) 
    ;  hTheme              - the theme data handle.  if non-NULL, will return
    ;                        size from [SysMetrics] section of theme.
    ;                        if NULL, will return the global system metric.
    ;  iSizeId             - the following values are supported when 
    ;                        hTheme is non-NULL:
    ;                          SM_CXBORDER       (border width)
    ;                          SM_CXVSCROLL      (scrollbar width)
    ;                          SM_CYHSCROLL      (scrollbar height)
    ;                          SM_CXSIZE         (caption width)
    ;                          SM_CYSIZE         (caption height)
    ;                          SM_CXSMSIZE       (small caption width)
    ;                          SM_CYSMSIZE       (small caption height)
    ;                          SM_CXMENUSIZE     (menubar width)
    ;                          SM_CYMENUSIZE     (menubar height)
    ;                          SM_CXPADDEDBORDER (padded border width)
    ;                        when hTheme is NULL, iSizeId is passed directly
    ;                        to the GetSystemMetrics() function
    ;---------------------------------------------------------------------------
    @DefProto DllImport, GetThemeSysSize, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD>, 8
    ;---------------------------------------------------------------------------
    ;  GetThemeSysFont()   - Get the LOGFONT for the specified System font. 
    ;  hTheme              - the theme data handle.  if non-NULL, will return
    ;                        font from [SysMetrics] section of theme.
    ;                        if NULL, will return the specified system font.
    ;  iFontId             - the TMT_XXX font number (first font
    ;                        is TMT_CAPTIONFONT)
    ;  plf                 - ptr to LOGFONT to receive the font value.
    ;                        (scaled for the current logical screen dpi) 
    ;---------------------------------------------------------------------------
    @DefProto DllImport, GetThemeSysFont, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :ptr LOGFONTW>, 12
    ;---------------------------------------------------------------------------
    ;  GetThemeSysString() - Get the value of specified System string metric. 
    ;  hTheme              - the theme data handle (required)
    ;  iStringId           - must be one of the following values:
    ;                          TMT_CSSNAME
    ;                          TMT_XMLNAME
    ;  pszStringBuff       - the buffer to receive the string value
    ;  cchMaxStringChars   - max. number of chars that pszStringBuff can hold
    ;---------------------------------------------------------------------------
    @DefProto DllImport, GetThemeSysString, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :LPWSTR, :SDWORD>, 16
    ;---------------------------------------------------------------------------
    ;  GetThemeSysInt() - Get the value of specified System int.
    ;  hTheme              - the theme data handle (required)
    ;  iIntId              - must be one of the following values:
    ;                          TMT_DPIX
    ;                          TMT_DPIY
    ;                          TMT_MINCOLORDEPTH
    ;  piValue             - ptr to int to receive value
    ;---------------------------------------------------------------------------
    @DefProto DllImport, GetThemeSysInt, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :ptr SDWORD>, 12
    ;---------------------------------------------------------------------------
    ;  IsThemeActive()     - can be used to test if a system theme is active
    ;                        for the current user session.  
    ;                        use the API "IsAppThemed()" to test if a theme is
    ;                        active for the calling process.
    ;---------------------------------------------------------------------------
    @DefProto DllImport, IsThemeActive, WIN_STD_CALL_CONV,, <>, 0
    ;---------------------------------------------------------------------------
    ;  IsAppThemed()       - returns TRUE if a theme is active and available to
    ;                        the current process
    ;---------------------------------------------------------------------------
    @DefProto DllImport, IsAppThemed, WIN_STD_CALL_CONV,, <>, 0
    ;---------------------------------------------------------------------------
    ;  GetWindowTheme()    - if window is themed, returns its most recent
    ;                        HTHEME from OpenThemeData() - otherwise, returns
    ;                        NULL.
    ;      hwnd            - the window to get the HTHEME of
    ;---------------------------------------------------------------------------
    @DefProto DllImport, GetWindowTheme, WIN_STD_CALL_CONV,, <:HWND>, 4
    ETDT_DISABLE equ 00000001h
    ETDT_ENABLE equ 00000002h
    ETDT_USETABTEXTURE equ 00000004h
    ETDT_ENABLETAB equ <(ETDT_ENABLE or ETDT_USETABTEXTURE)>
    if (NTDDI_VERSION ge NTDDI_VISTA)
      ETDT_USEAEROWIZARDTABTEXTURE equ 00000008h
      ETDT_ENABLEAEROWIZARDTAB equ <(ETDT_ENABLE or ETDT_USEAEROWIZARDTABTEXTURE)>
      ETDT_VALIDBITS equ <(ETDT_DISABLE or ETDT_ENABLE or ETDT_USETABTEXTURE or ETDT_USEAEROWIZARDTABTEXTURE)>
    endif
    ;---------------------------------------------------------------------------
    ;  EnableThemeDialogTexture() 
    ;  - Enables/disables dialog background theme.  This method can be used to 
    ;    tailor dialog compatibility with child windows and controls that 
    ;    may or may not coordinate the rendering of their client area backgrounds 
    ;    with that of their parent dialog in a manner that supports seamless 
    ;    background texturing.
    ;      hdlg         - the window handle of the target dialog
    ;      dwFlags      - ETDT_ENABLE to enable the theme-defined dialog background texturing,
    ;                     ETDT_DISABLE to disable background texturing,
    ;                     ETDT_ENABLETAB to enable the theme-defined background 
    ;                          texturing using the Tab texture
    ;---------------------------------------------------------------------------
    @DefProto DllImport, EnableThemeDialogTexture, WIN_STD_CALL_CONV,, <:HWND, :DWORD>, 8
    ;---------------------------------------------------------------------------
    ;  IsThemeDialogTextureEnabled() 
    ;  - Reports whether the dialog supports background texturing.
    ;      hdlg         - the window handle of the target dialog
    ;---------------------------------------------------------------------------
    @DefProto DllImport, IsThemeDialogTextureEnabled, WIN_STD_CALL_CONV,, <:HWND>, 4
    ;---------------------------------------------------------------------------
    ;---- flags to control theming within an app ----
    STAP_ALLOW_NONCLIENT equ (1 shl 0)
    STAP_ALLOW_CONTROLS equ (1 shl 1)
    STAP_ALLOW_WEBCONTENT equ (1 shl 2)
    STAP_VALIDBITS equ <(STAP_ALLOW_NONCLIENT or STAP_ALLOW_CONTROLS or STAP_ALLOW_WEBCONTENT)>
    ;---------------------------------------------------------------------------
    ;  GetThemeAppProperties()
    ;                      - returns the app property flags that control theming
    ;---------------------------------------------------------------------------
    @DefProto DllImport, GetThemeAppProperties, WIN_STD_CALL_CONV,, <>, 0
    ;---------------------------------------------------------------------------
    ;  SetThemeAppProperties()
    ;                      - sets the flags that control theming within the app
    ;      dwFlags         - the flag values to be set
    ;---------------------------------------------------------------------------
    @DefProto DllImport, SetThemeAppProperties, WIN_STD_CALL_CONV,, <:DWORD>, 4
    ;---------------------------------------------------------------------------
    ;  GetCurrentThemeName()
    ;                      - Get the name of the current theme in-use.  
    ;                        Optionally, return the ColorScheme name and the 
    ;                        Size name of the theme.
    ;  pszThemeFileName    - receives the theme path & filename
    ;  cchMaxNameChars     - max chars allowed in pszNameBuff
    ;  pszColorBuff        - (optional) receives the canonical color scheme name
    ;                        (not the display name)
    ;  cchMaxColorChars    - max chars allowed in pszColorBuff
    ;  pszSizeBuff         - (optional) receives the canonical size name 
    ;                        (not the display name)
    ;  cchMaxSizeChars     - max chars allowed in pszSizeBuff
    ;---------------------------------------------------------------------------
    @DefProto DllImport, GetCurrentThemeName, WIN_STD_CALL_CONV,, <:LPWSTR, :SDWORD, :LPWSTR, :SDWORD, :LPWSTR, :SDWORD>, 24
    SZ_THDOCPROP_DISPLAYNAME equ <L("DisplayName")>
    SZ_THDOCPROP_CANONICALNAME equ <L("ThemeName")>
    SZ_THDOCPROP_TOOLTIP equ <L("ToolTip")>
    SZ_THDOCPROP_AUTHOR equ <L("author")>
    @DefProto DllImport, GetThemeDocumentationProperty, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPCWSTR, :LPWSTR, :SDWORD>, 16
    ;---------------------------------------------------------------------------
    ;  Theme API Error Handling
    ;      All functions in the Theme API not returning an HRESULT (THEMEAPI_) 
    ;      use the WIN32 function "SetLastError()" to record any call failures.  
    ;      To retreive the error code of the last failure on the
    ;      current thread for these type of API's, use the WIN32 function 
    ;      "GetLastError()".
    ;      All Theme API error codes (HRESULT's and GetLastError() values)
    ;      should be normal win32 errors which can be formatted into
    ;      strings using the Win32 API FormatMessage().
    ;---------------------------------------------------------------------------
    ;---------------------------------------------------------------------------
    ; DrawThemeParentBackground()
    ;                      - used by partially-transparent or alpha-blended
    ;                        child controls to draw the part of their parent
    ;                        that they appear in front of.
    ;  hwnd                - handle of the child control
    ;  hdc                 - hdc of the child control
    ;  prc                 - (optional) rect that defines the area to be 
    ;                        drawn (CHILD coordinates)
    ;---------------------------------------------------------------------------
    @DefProto DllImport, DrawThemeParentBackground, WIN_STD_CALL_CONV,, <:HWND, :HDC, :ptr RECT>, 12
    ;---------------------------------------------------------------------------
    ;  EnableTheming()     - enables or disables themeing for the current user
    ;                        in the current and future sessions.
    ;  fEnable             - if FALSE, disable theming & turn themes off.
    ;                      - if TRUE, enable themeing and, if user previously
    ;                        had a theme active, make it active now.
    ;---------------------------------------------------------------------------
    @DefProto DllImport, EnableTheming, WIN_STD_CALL_CONV,, <:BOOL>, 4
    GBF_DIRECT equ 00000001h; direct dereferencing.

    GBF_COPY equ 00000002h; create a copy of the bitmap

    GBF_VALIDBITS equ <(GBF_DIRECT or GBF_COPY)>
    if (NTDDI_VERSION ge NTDDI_VISTA)
      DTPB_WINDOWDC equ 00000001h
      DTPB_USECTLCOLORSTATIC equ 00000002h
      DTPB_USEERASEBKGND equ 00000004h
      ;---------------------------------------------------------------------------
      ; DrawThemeParentBackgroundEx()
      ;                      - used by partially-transparent or alpha-blended
      ;                        child controls to draw the part of their parent
      ;                        that they appear in front of.
      ;                        Sends a WM_ERASEBKGND message followed by a WM_PRINTCLIENT.
      ;  hwnd                - handle of the child control
      ;  hdc                 - hdc of the child control
      ;  dwFlags             - if 0, only returns S_OK if the parent handled 
      ;                        WM_PRINTCLIENT.
      ;                      - if DTPB_WINDOWDC is set, hdc is assumed to be a window DC,
      ;                        not a client DC.
      ;                      - if DTPB_USEERASEBKGND is set, the function will return S_OK 
      ;                        without sending a WM_CTLCOLORSTATIC message if the parent 
      ;                        actually painted on WM_ERASEBKGND.
      ;                      - if DTPB_CTLCOLORSTATIC is set, the function will send
      ;                        a WM_CTLCOLORSTATIC message to the parent and use the 
      ;                        brush if one is provided, else COLOR_BTNFACE.
      ;  prc                 - (optional) rect that defines the area to be 
      ;                        drawn (CHILD coordinates)
      ;  Return value        - S_OK if something was painted, S_FALSE if not.
      ;---------------------------------------------------------------------------
      @DefProto DllImport, DrawThemeParentBackgroundEx, WIN_STD_CALL_CONV,, <:HWND, :HDC, :DWORD, :ptr RECT>, 16
      WINDOWTHEMEATTRIBUTETYPE typedef SDWORD
      WTA_NONCLIENT equ 1

      WTA_OPTIONS struct
        dwFlags DWORD ?
        ; values for each style option specified in the bitmask
        dwMask DWORD ?
        ; bitmask for flags that are changing
        ; valid options are: WTNCA_NODRAWCAPTION, WTNCA_NODRAWICON, WTNCA_NOSYSMENU
      WTA_OPTIONS ends
      _WTA_OPTIONS typedef WTA_OPTIONS
      PWTA_OPTIONS typedef ptr WTA_OPTIONS
      WTNCA_NODRAWCAPTION equ 00000001h; don't draw the window caption

      WTNCA_NODRAWICON equ 00000002h; don't draw the system icon

      WTNCA_NOSYSMENU equ 00000004h; don't expose the system menu icon functionality

      WTNCA_NOMIRRORHELP equ 00000008h; don't mirror the question mark, even in RTL layout

      WTNCA_VALIDBITS equ <(WTNCA_NODRAWCAPTION or WTNCA_NODRAWICON or WTNCA_NOSYSMENU or WTNCA_NOMIRRORHELP)>
      @DefProto DllImport, SetWindowThemeAttribute, WIN_STD_CALL_CONV,, <:HWND, :WINDOWTHEMEATTRIBUTETYPE, :PVOID, :DWORD>, 16
      SetWindowThemeNonClientAttributes proto WIN_STD_CALL_CONV :HWND, :DWORD, :DWORD
    endif
    ; (NTDDI_VERSION >= NTDDI_VISTA)
    ;---------------------------------------------------------------------------
    ; DrawThemeTextEx
    ; Note: DrawThemeTextEx only exists on Windows Vista and higher, but the 
    ; following declarations are provided to enable declaring its prototype when
    ; compiling for all platforms.
    ; Callback function used by DrawThemeTextEx, instead of DrawText
    TYPE_DTT_CALLBACK_PROC typedef proto WIN_STD_CALL_CONV :HDC, :LPWSTR, :SDWORD, :LPRECT, :UINT, :LPARAM
    DTT_CALLBACK_PROC typedef ptr TYPE_DTT_CALLBACK_PROC

    ;---- bits used in dwFlags of DTTOPTS ----
    DTT_TEXTCOLOR equ (1 shl 0); crText has been specified

    DTT_BORDERCOLOR equ (1 shl 1); crBorder has been specified

    DTT_SHADOWCOLOR equ (1 shl 2); crShadow has been specified

    DTT_SHADOWTYPE equ (1 shl 3); iTextShadowType has been specified

    DTT_SHADOWOFFSET equ (1 shl 4); ptShadowOffset has been specified

    DTT_BORDERSIZE equ (1 shl 5); iBorderSize has been specified

    DTT_FONTPROP equ (1 shl 6); iFontPropId has been specified

    DTT_COLORPROP equ (1 shl 7); iColorPropId has been specified

    DTT_STATEID equ (1 shl 8); IStateId has been specified

    DTT_CALCRECT equ (1 shl 9); Use pRect as and in/out parameter

    DTT_APPLYOVERLAY equ (1 shl 10); fApplyOverlay has been specified

    DTT_GLOWSIZE equ (1 shl 11); iGlowSize has been specified

    DTT_CALLBACK equ (1 shl 12); pfnDrawTextCallback has been specified

    DTT_COMPOSITED equ (1 shl 13); Draws text with antialiased alpha (needs a DIB section)

    DTT_VALIDBITS equ <(DTT_TEXTCOLOR or DTT_BORDERCOLOR or DTT_SHADOWCOLOR or DTT_SHADOWTYPE or DTT_SHADOWOFFSET or DTT_BORDERSIZE or DTT_FONTPROP or DTT_COLORPROP or DTT_STATEID or DTT_CALCRECT or DTT_APPLYOVERLAY or DTT_GLOWSIZE or DTT_COMPOSITED)>
    DTTOPTS struct
      dwSize DWORD ?
      ; size of the struct
      dwFlags DWORD ?
      ; which options have been specified
      crText COLORREF ?
      ; color to use for text fill
      crBorder COLORREF ?
      ; color to use for text outline
      crShadow COLORREF ?
      ; color to use for text shadow
      iTextShadowType SDWORD ?
      ; TST_SINGLE or TST_CONTINUOUS
      ptShadowOffset POINT <>
      ; where shadow is drawn (relative to text)
      iBorderSize SDWORD ?
      ; Border radius around text
      iFontPropId SDWORD ?
      ; Font property to use for the text instead of TMT_FONT
      iColorPropId SDWORD ?
      ; Color property to use for the text instead of TMT_TEXTCOLOR
      iStateId SDWORD ?
      ; Alternate state id
      fApplyOverlay DWORD ?
      ; Overlay text on top of any text effect?
      iGlowSize SDWORD ?
      ; Glow radious around text
      pfnDrawTextCallback DTT_CALLBACK_PROC ?
      ; Callback for DrawText
      lParam LPARAM ?
      ; Parameter for callback
    DTTOPTS ends
    _DTTOPTS typedef DTTOPTS
    PDTTOPTS typedef ptr DTTOPTS
    if (NTDDI_VERSION ge NTDDI_VISTA)
      @DefProto DllImport, DrawThemeTextEx, WIN_STD_CALL_CONV,, <:HTHEME, :HDC, :SDWORD, :SDWORD, :LPCWSTR, :SDWORD, :DWORD, :LPRECT, :ptr DTTOPTS>, 36
      ;-----------------------------------------------------------------------
      ;  GetThemeStream() - Get the value for the specified STREAM property
      ;      hTheme      - theme data handle
      ;      iPartId     - part number 
      ;      iStateId    - state number of part
      ;      iPropId     - the property number to get the value for
      ;      ppvStream   - if non-null receives the value of the STREAM property (not to be freed)
      ;      pcbStream   - if non-null receives the size of the STREAM property
      ;      hInst       - NULL when iPropId==TMT_STREAM, HINSTANCE of a loaded msstyles 
      ;                    file when iPropId==TMT_DISKSTREAM (use GetCurrentThemeName 
      ;                    and LoadLibraryEx(LOAD_LIBRARY_AS_DATAFILE)
      ;-----------------------------------------------------------------------
      @DefProto DllImport, GetThemeBitmap, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :ULONG, :ptr HBITMAP>, 24
      ;-----------------------------------------------------------------------
      ;  GetThemeStream() - Get the value for the specified STREAM property
      ;      hTheme      - theme data handle
      ;      iPartId     - part number 
      ;      iStateId    - state number of part
      ;      iPropId     - the property number to get the value for
      ;      ppvStream   - if non-null receives the value of the STREAM property (not to be freed)
      ;      pcbStream   - if non-null receives the size of the STREAM property
      ;      hInst       - NULL when iPropId==TMT_STREAM, HINSTANCE of a loaded msstyles 
      ;                    file when iPropId==TMT_DISKSTREAM (use GetCurrentThemeName 
      ;                    and LoadLibraryEx(LOAD_LIBRARY_AS_DATAFILE)
      ;-----------------------------------------------------------------------
      @DefProto DllImport, GetThemeStream, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :ptr ptr VOID, :ptr DWORD, :HINSTANCE>, 28
      ;------------------------------------------------------------------------
      ;  BufferedPaintInit() - Initialize the Buffered Paint API.
      ;                        Should be called prior to BeginBufferedPaint,
      ;                        and should have a matching BufferedPaintUnInit.
      ;------------------------------------------------------------------------
      @DefProto DllImport, BufferedPaintInit, WIN_STD_CALL_CONV,, <>, 0
      ;------------------------------------------------------------------------
      ;  BufferedPaintUnInit() - Uninitialize the Buffered Paint API.
      ;                          Should be called once for each call to BufferedPaintInit,
      ;                          when calls to BeginBufferedPaint are no longer needed.
      ;------------------------------------------------------------------------
      @DefProto DllImport, BufferedPaintUnInit, WIN_STD_CALL_CONV,, <>, 0
      ;------------------------------------------------------------------------
      ;  BeginBufferedPaint() - Begins a buffered paint operation.
      ;    hdcTarget          - Target DC on which the buffer will be painted
      ;    rcTarget           - Rectangle specifying the area of the target DC to paint to
      ;    dwFormat           - Format of the buffer (see BP_BUFFERFORMAT)
      ;    pPaintParams       - Paint operation parameters (see BP_PAINTPARAMS)
      ;    phBufferedPaint    - Pointer to receive handle to new buffered paint context
      ;------------------------------------------------------------------------
      ; HPAINTBUFFER
      HPAINTBUFFER typedef HANDLE
      ; handle to a buffered paint context
      ; BP_BUFFERFORMAT
      BP_BUFFERFORMAT typedef SDWORD
      BPBF_COMPATIBLEBITMAP equ 0
      ; Compatible bitmap
      BPBF_DIB equ 1
      ; Device-independent bitmap
      BPBF_TOPDOWNDIB equ 2
      ; Top-down device-independent bitmap
      BPBF_TOPDOWNMONODIB equ 3
      _BP_BUFFERFORMAT typedef BP_BUFFERFORMAT

      ; Top-down monochrome device-independent bitmap
      BPBF_COMPOSITED equ <BPBF_TOPDOWNDIB>
      ; BP_ANIMATIONSTYLE
      BP_ANIMATIONSTYLE typedef SDWORD
      BPAS_NONE equ 0
      ; No animation
      BPAS_LINEAR equ 1
      ; Linear fade animation
      BPAS_CUBIC equ 2
      ; Cubic fade animation
      BPAS_SINE equ 3
      _BP_ANIMATIONSTYLE typedef BP_ANIMATIONSTYLE

      ; Sinusoid fade animation
      ; BP_ANIMATIONPARAMS
      BP_ANIMATIONPARAMS struct
        cbSize DWORD ?
        dwFlags DWORD ?
        ; BPAF_ flags
        style BP_ANIMATIONSTYLE ?
        dwDuration DWORD ?
      BP_ANIMATIONPARAMS ends
      _BP_ANIMATIONPARAMS typedef BP_ANIMATIONPARAMS
      PBP_ANIMATIONPARAMS typedef ptr BP_ANIMATIONPARAMS
      BPPF_ERASE equ 0001h; Empty the buffer during BeginBufferedPaint()

      BPPF_NOCLIP equ 0002h; Don't apply the target DC's clip region to the double buffer

      BPPF_NONCLIENT equ 0004h; Using a non-client DC

      ; BP_PAINTPARAMS
      BP_PAINTPARAMS struct
        cbSize DWORD ?
        dwFlags DWORD ?
        ; BPPF_ flags
        prcExclude POINTER ?
        pBlendFunction POINTER ?
      BP_PAINTPARAMS ends
      _BP_PAINTPARAMS typedef BP_PAINTPARAMS
      PBP_PAINTPARAMS typedef ptr BP_PAINTPARAMS
      @DefProto DllImport, BeginBufferedPaint, WIN_STD_CALL_CONV,, <:HDC, :ptr RECT, :BP_BUFFERFORMAT, :ptr BP_PAINTPARAMS, :ptr HDC>, 20
      ;------------------------------------------------------------------------
      ;  EndBufferedPaint() - Ends a buffered paint operation.
      ;    hBufferedPaint   - handle to buffered paint context
      ;    fUpdateTarget    - update target DC
      ;------------------------------------------------------------------------
      @DefProto DllImport, EndBufferedPaint, WIN_STD_CALL_CONV,, <:HPAINTBUFFER, :BOOL>, 8
      ;------------------------------------------------------------------------
      ;  GetBufferedPaintTargetRect() - Returns the target rectangle specified during BeginBufferedPaint
      ;    hBufferedPaint             - handle to buffered paint context
      ;    prc                        - pointer to receive target rectangle
      ;------------------------------------------------------------------------
      @DefProto DllImport, GetBufferedPaintTargetRect, WIN_STD_CALL_CONV,, <:HPAINTBUFFER, :ptr RECT>, 8
      ;------------------------------------------------------------------------
      ;  GetBufferedPaintTargetDC() - Returns the target DC specified during BeginBufferedPaint
      ;    hBufferedPaint           - handle to buffered paint context
      ;------------------------------------------------------------------------
      @DefProto DllImport, GetBufferedPaintTargetDC, WIN_STD_CALL_CONV,, <:HPAINTBUFFER>, 4
      ;------------------------------------------------------------------------
      ;  GetBufferedPaintDC() - Returns the same paint DC returned by BeginBufferedPaint
      ;    hBufferedPaint     - handle to buffered paint context
      ;------------------------------------------------------------------------
      @DefProto DllImport, GetBufferedPaintDC, WIN_STD_CALL_CONV,, <:HPAINTBUFFER>, 4
      ;------------------------------------------------------------------------
      ;  GetBufferedPaintBits() - Obtains a pointer to the buffer bitmap, if the buffer is a DIB
      ;    hBufferedPaint       - handle to buffered paint context
      ;    ppbBuffer            - pointer to receive pointer to buffer bitmap pixels
      ;    pcxRow               - pointer to receive width of buffer bitmap, in pixels;
      ;                           this value may not necessarily be equal to the buffer width
      ;------------------------------------------------------------------------
      @DefProto DllImport, GetBufferedPaintBits, WIN_STD_CALL_CONV,, <:HPAINTBUFFER, :ptr ptr RGBQUAD, :ptr SDWORD>, 12
      ;------------------------------------------------------------------------
      ;  BufferedPaintClear() - Clears given rectangle to ARGB = {0, 0, 0, 0}
      ;    hBufferedPaint     - handle to buffered paint context
      ;    prc                - rectangle to clear; NULL specifies entire buffer
      ;------------------------------------------------------------------------
      @DefProto DllImport, BufferedPaintClear, WIN_STD_CALL_CONV,, <:HPAINTBUFFER, :ptr RECT>, 8
      ;------------------------------------------------------------------------
      ;  BufferedPaintSetAlpha() - Set alpha to given value in given rectangle
      ;    hBufferedPaint        - handle to buffered paint context
      ;    prc                   - rectangle to set alpha in; NULL specifies entire buffer
      ;    alpha                 - alpha value to set in the given rectangle
      ;------------------------------------------------------------------------
      @DefProto DllImport, BufferedPaintSetAlpha, WIN_STD_CALL_CONV,, <:HPAINTBUFFER, :ptr RECT, :BYTE>, 12
      ; Macro for setting the buffer to opaque (alpha = 255)
      BufferedPaintMakeOpaque macro hBufferedPaint, prc
        exitm <BufferedPaintSetAlpha (hBufferedPaint, prc, 255)>
      endm
      ;------------------------------------------------------------------------
      ;  BufferedPaintStopAllAnimations() - Stop all buffer animations for the given window
      ;    hwnd                           - window on which to stop all animations
      ;------------------------------------------------------------------------
      @DefProto DllImport, BufferedPaintStopAllAnimations, WIN_STD_CALL_CONV,, <:HWND>, 4
      HANIMATIONBUFFER typedef HANDLE
      ; handle to a buffered paint animation
      @DefProto DllImport, BeginBufferedAnimation, WIN_STD_CALL_CONV,, <:HWND, :HDC, :ptr RECT, :BP_BUFFERFORMAT, :ptr BP_PAINTPARAMS, :ptr BP_ANIMATIONPARAMS, :ptr HDC, :ptr HDC>, 32
      @DefProto DllImport, EndBufferedAnimation, WIN_STD_CALL_CONV,, <:HANIMATIONBUFFER, :BOOL>, 8
      @DefProto DllImport, BufferedPaintRenderAnimation, WIN_STD_CALL_CONV,, <:HWND, :HDC>, 8
      ;----------------------------------------------------------------------------
      ; Tells if the DWM is running, and composition effects are possible for this 
      ; process (themes are active). 
      ; Roughly equivalent to "DwmIsCompositionEnabled() && IsAppthemed()"
      ;----------------------------------------------------------------------------
      @DefProto DllImport, IsCompositionActive, WIN_STD_CALL_CONV,, <>, 0
      ;------------------------------------------------------------------------
      ;  GetThemeTransitionDuration()
      ;                      - Gets the duration for the specified transition
      ;  hTheme              - theme data handle
      ;  iPartId             - part number 
      ;  iStateIdFrom        - starting state number of part
      ;  iStateIdTo          - ending state number of part
      ;  iPropId             - property id 
      ;  pdwDuration         - receives the transition duration
      ;------------------------------------------------------------------------
      @DefProto DllImport, GetThemeTransitionDuration, WIN_STD_CALL_CONV,, <:HTHEME, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :ptr DWORD>, 24
    endif
    ; (NTDDI_VERSION >= NTDDI_VISTA)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  ;* _UXTHEME_H_ *
endif
