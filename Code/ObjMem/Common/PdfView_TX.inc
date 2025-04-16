; ==================================================================================================
; Title:      PdfView_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017.
;               - First release.
;               - Character and bitness neutral code. 
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  PdfViewA / PdfViewW
; Purpose:    Display a PDF document on a named destination.
; Arguments:  Arg1: Parent HANDLE.
;             Arg2: -> PDF document.
;             Arg3: -> Destination.
; Return:     eax = HINSTANCE. See ShellExecute return values. 
;             A value greater than 32 indicates success.

.code
align ALIGN_CODE
ProcName proc uses xbx hParent:HWND, pFileName:POINTER, pDestination:POINTER
  local cApplication[1024]:CHR, dChrCnt:DWORD
  local cCommand[1024]:CHR

  .if pFileName != NULL
    mov dChrCnt, lengthof(cApplication)                   ;ZTC Included
    invoke AssocQueryString, 0, ASSOCSTR_EXECUTABLE, $OfsCStr(".pdf"), $OfsCStr("open"), \
                             addr cApplication, addr dChrCnt
    .if eax == S_OK
      .if pDestination != NULL
        lea xbx, [cCommand + sizeof(cCommand)]
        FillText cCommand, </A "nameddest=>
        invoke StrCECopy, addr(cCommand + sizeof(CHR)*14), pDestination, lengthof(cCommand) - 14 - 1
        lea xcx, [xax + 3*sizeof(CHR)]
        .if xcx < xbx
          FillText [xax], <" ">
          mov xax, xbx
          sub xax, xcx
          if TARGET_STR_TYPE eq STR_TYPE_WIDE
            shr xax, 1
          endif
          dec xax
          invoke StrCECopy, xcx, pFileName, eax
          lea xcx, [xax + 2*sizeof(CHR)]
          .if xcx < xbx
            FillString [xax], <">
            invoke ShellExecute, hParent, $OfsCStr("open"), addr cApplication, \
                                 addr cCommand, NULL, SW_SHOW
          .else
            xor eax, eax
          .endif
        .else
          xor eax, eax
        .endif
      .else
        invoke ShellExecute, hParent, $OfsCStr("open"), addr cApplication, \
                             pFileName, NULL, SW_SHOW
      .endif
    .endif
  .endif
  ret
ProcName endp
