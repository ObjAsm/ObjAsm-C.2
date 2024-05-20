;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\sphelper.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 12/02/2024 17:05:48

;*******************************************************************************
ifndef SPHelper_h
  SPHelper_h equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef _INC_MALLOC
      include malloc.inc
    endif
    ifndef __sapi_h__
      include sapi.inc
    endif
    ifndef __sapiddk_h__
      include sapiddk.inc
    endif
    ifndef SPError_h
      include SPError.inc
    endif
    ifndef _INC_LIMITS
      include limits.inc
    endif
    ifndef _INC_MMSYSTEM
      include mmsystem.inc
    endif
    ifndef __comcat_h__
      include comcat.inc
    endif
    ifndef _INC_MMREG
      include mmreg.inc
    endif
    ifndef __ATLBASE_H__
      include atlbase.inc
    endif
    include wchar.inc
    include tchar.inc
    include strsafe.inc
    include intsafe.inc
    ifndef _PREFAST_
    endif
    ifndef REG_MUI_STRING_TRUNCATE
      REG_MUI_STRING_TRUNCATE equ 00000001h
    endif
    ;=== Constants ==============================================================
    sp_countof macro x
      exitm <((sizeof(x) / sizeof(* (x))))>
    endm
    ;*** CSpDynamicString helper class
    ;*
    ;*
    ;*explicit*
    ;*explicit*
    ;*explicit*
    ;*explicit*
    ; Too long
    ;The assert on operator& usually indicates a bug.  If this is really
    ;what is needed, however, take the address of the m_psz member explicitly.
    ; Versions of Append that return HRESULT
    ; Could append to an empty string so check...
    ; Original versions of Append that do not return HRESULTs
    ; Version of Append2 that returns HRESULT
    ; Could append to an empty string so check...
    ; In both of these cases, we copy the trailing NULL so that we're sure it gets
    ; there (if lenSrc2 is 0 then we better copy it from pszSrc1).
    ; Original version of Append2 that does not return HRESULT
    ;*++
    ;Routine Description:
    ;This routine determines if the currently executing context is running as an
    ;AppContainer.
    ;Arguments:
    ;[out] IsAppContainer - Set to TRUE if this is an AppContainer, FALSE 
    ;otherwise.
    ;Return Value:
    ;ERROR_SUCCESS or an appropriate error code.
    ;--*
    ; The logic for this function is as follows:
    ; Attempt to open the thread token, if that fails then open the process
    ; token.
    ; Query the token for TokenIsAppContainer, if that succeeds then determine
    ; if the value returned indicated that this is an AppContainer.
    ; All failure paths will result in IsAppContainer being FALSE and return
    ; an appropriate error code.
    ; First try to open the thread token (if we're impersonating).
    ;Needs to be true if the token has only the SecurityIdentify impersonation level, see http://msdn.microsoft.com/en-us/library/aa379296(VS.85).aspx
    ; If the token is anonymous or there is a error other than 
    ; ERROR_NO_TOKEN, then fail here as we can't determine the 
    ; caller.
    ; Since we could not open the thread token (not impersonating),
    ; attempt to open the process token.
    ; Query the token to determine if this is an AppContainer.
    ; This is an AppContainer, so indicate that to the caller.
    ;  Simple inline function converts a ulong to a hex string.
    ; If for some reason we cannot convert a number, set it to 0
    if Defined(_WIN32_WCE) and (_WIN32_WCE lt 600h)
    else
    endif
    ; Convert the token to its numeral form in a WCHAR
    ; character in the range ':' .. '@'
    ;=== Token helpers
    ; Set the new token's CLSID (if specified)
    ; Set the token's lang independent name
    ; Set the token's lang dependent name
    ; Open the attributes key if requested
    ; Forcefully create the token
    ; Forcefully create the category
    ; Come up with a token key name if one wasn't specified
    ; Build the token id
    ; Forcefully create the token
    ; Create the new token
    ; Now set the extra data
    ; Create the new token
    ; only set the extra data when not running in app chamber, if we failed the call to check if in chamber default to old sapi behavior.
    ; Now set the extra data
    ; append VendorPreferred to the end of pszOptAttribs to force this preference
    ; including 1 char here for null terminator
    ; including 1 char here for null terminator
    ; If not IPA or UPS
    if _SAPI_VER ge 053h
      ; If we cannot find a phone converter, use the Universal Phone Converter as default
      ; We cannot query for the new interface, reset the error code
    endif
    ; LangIds cannot be more than 4 characters longs
    ; check if the langid is in the format "409;9" - extract the "409" in this case
    ;****************************************************************************
    ;* SpHrFromWin32 *
    ;*---------------*
    ;*   Description:
    ;*       This inline function works around a basic problem with the macro
    ;*   HRESULT_FROM_WIN32.  The macro forces the expresion in ( ) to be evaluated
    ;*   two times.  By using this inline function, the expression will only be
    ;*   evaluated once.
    ;*
    ;*   Returns:
    ;*       HRESULT of converted Win32 error code
    ;*
    ;*****************************************************************************
    ;****************************************************************************
    ;* SpHrFromLastWin32Error *
    ;*------------------------*
    ;*   Description:
    ;*       This simple inline function is used to return a converted HRESULT
    ;*   from the Win32 function ::GetLastError.  Note that using HRESULT_FROM_WIN32
    ;*   will evaluate the error code twice so we don't want to use:
    ;*
    ;*       HRESULT_FROM_WIN32(::GetLastError()) 
    ;*
    ;*   since that will call GetLastError twice.
    ;*
    ;*   Returns:
    ;*       HRESULT for ::GetLastError(). If the HRESULT is a success code, this 
    ;*       function will return E_FAIL to guarantee an error return code.
    ;*
    ;*****************************************************************************
    ;****************************************************************************
    ;* SpGetUserDefaultUILanguage *
    ;*----------------------------*
    ;*   Description:
    ;*       Now that we only support XP & Above, this is a straight call to
    ;*       GetUserDefaultUILanguage
    ;*
    ;*   Returns:
    ;*       Default UI language
    ;*
    ;*****************************************************************************
    if _SAPI_VER ge 053h
      ; Windows Vista does not encourage localized strings in the registry
      ; When running on Windows Vista query the localized engine name from a resource dll
      ; If we reach this code we are running under Windows Vista
      ; Delay bind with RegLoadMUIStringW since this function is not supported on previous versions of advapi32.dll
      ; RegLoadMUIStringW is supported only on advapi32.dll that ships with Windows Vista  and above
      ; Calling RegLoadMUIStringW directly makes the loader try to resolve the function reference at load time which breaks,
      ; hence we manually load advapi32.dll, query for the function pointer and invoke it.
      ; This should not happen in Vista
      ; Find the first occurance of '\\' in the absolute registry key path
      ; pRegKeyPath now points to the path to the recognizer token under the HKLM or HKCR hive
      ; Open the registry key for read and get the handle
      ; Use MUI RegLoadMUIStringW API to load the localized string
      ; This should be enough memory to allocate the localized Engine Name
      ; pRegKeyPath should never be 0 if we are querying for relative hkey path
      ; Close registry key handle
      ; Free memory allocated to locals
      ; If running on OSes released before Windows Vista query the localized string from the registry
      ; If RegLoadMUIStringW failed to retrieved the localized Engine name retrieve the localized string from the fallback (Default) attribute
    else
    endif
    ; _SAPI_VER >= 0x053
    ; Free memory allocated above if necessary
    ;****************************************************************************
    ;* SpConvertStreamFormatEnum *
    ;*---------------------------*
    ;*   Description:
    ;*       This method converts the specified stream format into a wave format
    ;*   structure.
    ;*
    ;*****************************************************************************
    ; Assume failure case
    ;--- Some of these values seem odd. We used what the codec told us.
    ;--- Some of these values seem odd. We used what the codec told us.
    ; There are other fields like wBitsPerSample but these can be zero in some formats.
    ; Add the extra data size in but ignore for WAVE_FORMAT_PCM {accoring to MSDN this should be ignored}.
    ; Always set cbSize to zero for WAVE_FORMAT_PCM.
    ; Always set cbSize to zero for WAVE_FORMAT_PCM.
    ;  It is a WAVEFORMATEX.  Now determine which type it is and convert.
    ; Fall through
    ; Fall through
    ; Fall through
    ; Fall through
    ; Fall through
    ; Fall through
    ; Fall through
    ; Fall through
    ; fall through
    ; Fall through
    ; Fall through
    ; Fall through
    ; Add 3 to round up
    ; Round to DWORD
    ; check pointer to pBuffer for size value
    ; check complete pBuffer from start
    ; Return the default codepage given a LCID.
    ; Note some of the newer locales do not have associated Windows codepages.  For these, we return UTF-8.
    ;* SPBindToFile *
    ;****************************************************************************
    ;* CheckStringSizeBytes *
    ;*--------------*
    ;*   Description:
    ;*       Checks a string is not longer that the supplied size {IN BYTES}, including
    ;*       the terminating char. If pcb is non-null then it is set to the size of 
    ;*       the string {IN BYTES}, including the terminating char.
    ;*
    ;*****************************************************************************
    ; the string is longer than cchMax
    ;****************************************************************************
    ;* SpClearEvent *
    ;*--------------*
    ;*   Description:
    ;*       Helper function that can be used by clients that do not use the CSpEvent
    ;*   class.
    ;*
    ;*   Returns:
    ;*
    ;*****************************************************************************
    ;****************************************************************************
    ;* SpInitEvent *
    ;*-------------*
    ;*   Description:
    ;*
    ;*   Returns:
    ;*
    ;*****************************************************************************
    ;****************************************************************************
    ;* SpEventSerializeSize *
    ;*----------------------*
    ;*   Description:
    ;*       Computes the required size of a buffer to serialize an event.  The caller
    ;*   must specify which type of serialized event is desired -- either SPSERIALIZEDEVENT
    ;*   or SPSERIALIZEDEVENT64.    
    ;*
    ;*   Returns:
    ;*       Size in bytes required to seriailze the event.
    ;*
    ;****************************************************************************
    ; Would be better to check for overflow of string length.
    ; Round up to nearest DWORD
    ;****************************************************************************
    ;* SpSerializedEventSize *
    ;*-----------------------*
    ;*   Description:
    ;*       Returns the size, in bytes, used by a serialized event.  The caller can
    ;*   pass a pointer to either a SPSERIAILZEDEVENT or SPSERIALIZEDEVENT64 structure.
    ;*
    ;*   Returns:
    ;*       Number of bytes used by serizlied event
    ;*
    ;*****************************************************************************
    ; Round up to nearest DWORD
    ;*** CSpEvent helper class
    ;*
    ;*
    ; If you need to take the address of a CSpEvent that is not const, use the AddrOf() method
    ; which will do debug checking of parameters.  If you encounter this problem when calling
    ; GetEvents from an event source, you may want to use the GetFrom() method of this class.
    ; Note:  This method does not ASSERT since we assume the caller knows what they are doing.
    ; Call this method with either SPSERIALIZEDEVENT or SPSERIALIZEDEVENT64
    ; Call this method with either SPSERIALIZEDEVENT or SPSERIALIZEDEVENT64
    ; pTemp->SerializedlParam is 0
    ; lParam can't be a Token
    ; Reset the data structure on failure.  Otherwise, the destructor may AV.
    ;  Helpers for access to events.  Performs run-time checks in debug and casts
    ;  data to the appropriate types
    ; More explicit check than ObjectToken()
    if _SAPI_VER ge 053h
    endif
    if _SAPI_VER ge 053h
    endif
    ; Note: Don't use String() method here since in the case of string attributes, the elParamType
    ; field specifies LPARAM_IS_POINTER, but the attribute name IS the first string in this buffer
    ; Search for the first NULL and return pointer to the char past it.
    ;The assert on operator& usually indicates a bug.  If this is really
    ;what is needed, however, take the address of the m_pPhrase member explicitly.
    ; Keep the old behavior, the pointer becomes NULL if we fail above
    ;The assert on operator& usually indicates a bug.  If this is really
    ;what is needed, however, take the address of the m_pT member explicitly.
    ;**** Helper function used to create a new phrase object from an array of
    ;test words. Each word in the string is converted to a phrase element.
    ;This is useful to create a phrase to pass to the EmulateRecognition method.
    ;The method can convert standard words as well as words with the
    ;"/display_text/lexical_form/pronounciation;" word format.
    ;You can also specify the DisplayAttributes for each element if desired. 
    ;If prgDispAttribs is NULL then the DisplayAttribs for each element default to 
    ;SPAF_ONE_TRAILING_SPACE. ****
    ifdef SP_SPPHRASESIZE_500
    else
    endif
    ;This is a compound word
    ; Find the second separator slash.
    ; We stopped at the second '/'
    ; We stopped at the third '/'
    ;It is the simple format, only have one form, use it for everything.
    ; Emulated results give confidence of 1.0
    ;**** Helper function used to create a new phrase object from a 
    ;test string. Each word in the string is converted to a phrase element.
    ;This is useful to create a phrase to pass to the EmulateRecognition method.
    ;The method can convert standard words as well as words with the
    ;"/display_text/lexical_form/pronounciation;" word format.
    ;If the emulation needs to match word sequence data (textbuffer) then
    ;the corresponding words need to be bracketed with '[' and ']' so they
    ;can be put into a single phrase element
    ;****
    ;We first trim the input text
    ; Set first array pointer (if *p).
    ; Skip leading white spaces
    ; Skip over word
    ; Skip all non-semicolon characters and unescape escaped characters
    ; Skip all non-whitespace characters
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  ;* This must be the last line in the file *
endif
