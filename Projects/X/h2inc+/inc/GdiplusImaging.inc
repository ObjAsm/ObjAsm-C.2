;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdiplusimaging.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:52

;\**************************************************************************
ifndef _GDIPLUSIMAGING_H
  _GDIPLUSIMAGING_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if _MSC_VER ge 1200
      ;* padding added after data member *
    endif
    ;---------------------------------------------------------------------------
    ; Image file format identifiers
    ;---------------------------------------------------------------------------
    DEFINE_GUID ImageFormatUndefined, 0b96b3ca9h, 0728h, 11d3h, 9dh, 7bh, 00h, 00h, 0f8h, 1eh, 0f3h, 2eh
    DEFINE_GUID ImageFormatMemoryBMP, 0b96b3caah, 0728h, 11d3h, 9dh, 7bh, 00h, 00h, 0f8h, 1eh, 0f3h, 2eh
    DEFINE_GUID ImageFormatBMP, 0b96b3cabh, 0728h, 11d3h, 9dh, 7bh, 00h, 00h, 0f8h, 1eh, 0f3h, 2eh
    DEFINE_GUID ImageFormatEMF, 0b96b3cach, 0728h, 11d3h, 9dh, 7bh, 00h, 00h, 0f8h, 1eh, 0f3h, 2eh
    DEFINE_GUID ImageFormatWMF, 0b96b3cadh, 0728h, 11d3h, 9dh, 7bh, 00h, 00h, 0f8h, 1eh, 0f3h, 2eh
    DEFINE_GUID ImageFormatJPEG, 0b96b3caeh, 0728h, 11d3h, 9dh, 7bh, 00h, 00h, 0f8h, 1eh, 0f3h, 2eh
    DEFINE_GUID ImageFormatPNG, 0b96b3cafh, 0728h, 11d3h, 9dh, 7bh, 00h, 00h, 0f8h, 1eh, 0f3h, 2eh
    DEFINE_GUID ImageFormatGIF, 0b96b3cb0h, 0728h, 11d3h, 9dh, 7bh, 00h, 00h, 0f8h, 1eh, 0f3h, 2eh
    DEFINE_GUID ImageFormatTIFF, 0b96b3cb1h, 0728h, 11d3h, 9dh, 7bh, 00h, 00h, 0f8h, 1eh, 0f3h, 2eh
    DEFINE_GUID ImageFormatEXIF, 0b96b3cb2h, 0728h, 11d3h, 9dh, 7bh, 00h, 00h, 0f8h, 1eh, 0f3h, 2eh
    DEFINE_GUID ImageFormatIcon, 0b96b3cb5h, 0728h, 11d3h, 9dh, 7bh, 00h, 00h, 0f8h, 1eh, 0f3h, 2eh
    DEFINE_GUID ImageFormatHEIF, 0b96b3cb6h, 0728h, 11d3h, 9dh, 7bh, 00h, 00h, 0f8h, 1eh, 0f3h, 2eh
    DEFINE_GUID ImageFormatWEBP, 0b96b3cb7h, 0728h, 11d3h, 9dh, 7bh, 00h, 00h, 0f8h, 1eh, 0f3h, 2eh
    ;---------------------------------------------------------------------------
    ; Predefined multi-frame dimension IDs
    ;---------------------------------------------------------------------------
    DEFINE_GUID FrameDimensionTime, 6aedbd6dh, 3fb5h, 418ah, 83h, 0a6h, 7fh, 45h, 22h, 9dh, 0c8h, 72h
    DEFINE_GUID FrameDimensionResolution, 84236f7bh, 3bd3h, 428fh, 8dh, 0abh, 4eh, 0a1h, 43h, 9ch, 0a3h, 15h
    DEFINE_GUID FrameDimensionPage, 7462dc86h, 6180h, 4c7eh, 8eh, 3fh, 0eeh, 73h, 33h, 0a7h, 0a4h, 83h
    ;---------------------------------------------------------------------------
    ; Property sets
    ;---------------------------------------------------------------------------
    DEFINE_GUID FormatIDImageInformation, 0e5836cbeh, 5eefh, 4f1dh, 0ach, 0deh, 0aeh, 4ch, 43h, 0b6h, 08h, 0ceh
    DEFINE_GUID FormatIDJpegAppHeaders, 1c4afdcdh, 6177h, 43cfh, 0abh, 0c7h, 5fh, 51h, 0afh, 39h, 0eeh, 85h
    ;---------------------------------------------------------------------------
    ; Encoder parameter sets
    ;---------------------------------------------------------------------------
    DEFINE_GUID EncoderCompression, 0e09d739dh, 0ccd4h, 44eeh, 8eh, 0bah, 3fh, 0bfh, 8bh, 0e4h, 0fch, 58h
    DEFINE_GUID EncoderColorDepth, 66087055h, 0ad66h, 4c7ch, 9ah, 18h, 38h, 0a2h, 31h, 0bh, 83h, 37h
    DEFINE_GUID EncoderScanMethod, 3a4e2661h, 3109h, 4e56h, 85h, 36h, 42h, 0c1h, 56h, 0e7h, 0dch, 0fah
    DEFINE_GUID EncoderVersion, 24d18c76h, 814ah, 41a4h, 0bfh, 53h, 1ch, 21h, 9ch, 0cch, 0f7h, 97h
    DEFINE_GUID EncoderRenderMethod, 6d42c53ah, 229ah, 4825h, 8bh, 0b7h, 5ch, 99h, 0e2h, 0b9h, 0a8h, 0b8h
    DEFINE_GUID EncoderQuality, 1d5be4b5h, 0fa4ah, 452dh, 9ch, 0ddh, 5dh, 0b3h, 51h, 05h, 0e7h, 0ebh
    DEFINE_GUID EncoderTransformation, 8d0eb2d1h, 0a58eh, 4ea8h, 0aah, 14h, 10h, 80h, 74h, 0b7h, 0b6h, 0f9h
    DEFINE_GUID EncoderLuminanceTable, 0edb33bceh, 0266h, 4a77h, 0b9h, 04h, 27h, 21h, 60h, 99h, 0e7h, 17h
    DEFINE_GUID EncoderChrominanceTable, 0f2e455dch, 09b3h, 4316h, 82h, 60h, 67h, 6ah, 0dah, 32h, 48h, 1ch
    DEFINE_GUID EncoderSaveFlag, 292266fch, 0ac40h, 47bfh, 8ch, 0fch, 0a8h, 5bh, 89h, 0a6h, 55h, 0deh
    if (GDIPVER ge 0110h)
      DEFINE_GUID EncoderColorSpace, 0ae7a62a0h, 0ee2ch, 49d8h, 9dh, 7h, 1bh, 0a8h, 0a9h, 27h, 59h, 6eh
      DEFINE_GUID EncoderImageItems, 63875e13h, 1f1dh, 45abh, 91h, 95h, 0a2h, 9bh, 60h, 66h, 0a6h, 50h
      DEFINE_GUID EncoderSaveAsCMYK, 0a219bbc9h, 0a9dh, 4005h, 0a3h, 0eeh, 3ah, 42h, 1bh, 8bh, 0b0h, 6ch
    endif
    ;(GDIPVER >= 0x0110)
    DEFINE_GUID CodecIImageBytes, 025d1823h, 6c7dh, 447bh, 0bbh, 0dbh, 0a3h, 0cbh, 0c3h, 0dfh, 0a2h, 0fch
    MIDL_INTERFACE("025D1823-6C7D-447B-BBDB-A3CBC3DFA2FC")
      ; Return total number of bytes in the IStream
      STDMETHOD CountBytes, :ptr DWORD
      ; Locks "cb" bytes, starting from "ulOffset" in the stream, and returns the
      ; pointer to the beginning of the locked memory chunk in "ppvBytes"
      STDMETHOD LockBytes, :DWORD, :DWORD, :ptr ptr 
      ; Unlocks "cb" bytes, pointed by "pvBytes", starting from "ulOffset" in the
      ; stream
      STDMETHOD UnlockBytes, :ptr , :DWORD, :DWORD
    MIDL_INTERFACE_END

    ;--------------------------------------------------------------------------
    ; ImageCodecInfo structure
    ;--------------------------------------------------------------------------
    ;--------------------------------------------------------------------------
    ; Information flags about image codecs
    ;--------------------------------------------------------------------------
    ;---------------------------------------------------------------------------
    ; Access modes used when calling Image::LockBits
    ;---------------------------------------------------------------------------
    ;---------------------------------------------------------------------------
    ; Information about image pixel data
    ;---------------------------------------------------------------------------
    ;---------------------------------------------------------------------------
    ; Image flags
    ;---------------------------------------------------------------------------
    ; Low-word: shared with SINKFLAG_x
    ; Low-word: color space definition
    ; Low-word: image size info
    ; High-word
    ;---------------------------------------------------------------------------
    ; Encoder Parameter structure
    ;---------------------------------------------------------------------------
    ; GUID of the parameter
    ; Number of the parameter values
    ; Value type, like ValueTypeLONG  etc.
    ; A pointer to the parameter values
    ;---------------------------------------------------------------------------
    ; Encoder Parameters structure
    ;---------------------------------------------------------------------------
    ; Number of parameters in this structure
    ; Parameter values
    if (GDIPVER ge 0110h)
      ;---------------------------------------------------------------------------
      ; External Data Item
      ;---------------------------------------------------------------------------
      ; size of the structure 
      ; flags describing how the data is to be used.
      ; description on how the data is to be saved.
      ; it is different for every codec type.
      ; size memory pointed by Desc
      ; pointer to the data that is to be saved in the
      ; file, could be anything saved directly.
      ; size memory pointed by Data
      ; opaque for the apps data member used during
      ; enumeration of image data items.
    endif
    ;(GDIPVER >= 0x0110)
    ;---------------------------------------------------------------------------
    ; Property Item
    ;---------------------------------------------------------------------------
    ; ID of this property
    ; Length of the property value, in bytes
    ; Type of the value, as one of TAG_TYPE_XXX
    ; defined above
    ; property value
    ;---------------------------------------------------------------------------
    ; Image property types 
    ;---------------------------------------------------------------------------
    PropertyTagTypeByte equ 1
    PropertyTagTypeASCII equ 2
    PropertyTagTypeShort equ 3
    PropertyTagTypeLong equ 4
    PropertyTagTypeRational equ 5
    PropertyTagTypeUndefined equ 7
    PropertyTagTypeSLONG equ 9
    PropertyTagTypeSRational equ 10
    ;---------------------------------------------------------------------------
    ; Image property ID tags
    ;---------------------------------------------------------------------------
    PropertyTagExifIFD equ 8769h
    PropertyTagGpsIFD equ 8825h
    PropertyTagNewSubfileType equ 00FEh
    PropertyTagSubfileType equ 00FFh
    PropertyTagImageWidth equ 0100h
    PropertyTagImageHeight equ 0101h
    PropertyTagBitsPerSample equ 0102h
    PropertyTagCompression equ 0103h
    PropertyTagPhotometricInterp equ 0106h
    PropertyTagThreshHolding equ 0107h
    PropertyTagCellWidth equ 0108h
    PropertyTagCellHeight equ 0109h
    PropertyTagFillOrder equ 010Ah
    PropertyTagDocumentName equ 010Dh
    PropertyTagImageDescription equ 010Eh
    PropertyTagEquipMake equ 010Fh
    PropertyTagEquipModel equ 0110h
    PropertyTagStripOffsets equ 0111h
    PropertyTagOrientation equ 0112h
    PropertyTagSamplesPerPixel equ 0115h
    PropertyTagRowsPerStrip equ 0116h
    PropertyTagStripBytesCount equ 0117h
    PropertyTagMinSampleValue equ 0118h
    PropertyTagMaxSampleValue equ 0119h
    PropertyTagXResolution equ 011Ah; Image resolution in width direction

    PropertyTagYResolution equ 011Bh; Image resolution in height direction

    PropertyTagPlanarConfig equ 011Ch; Image data arrangement

    PropertyTagPageName equ 011Dh
    PropertyTagXPosition equ 011Eh
    PropertyTagYPosition equ 011Fh
    PropertyTagFreeOffset equ 0120h
    PropertyTagFreeByteCounts equ 0121h
    PropertyTagGrayResponseUnit equ 0122h
    PropertyTagGrayResponseCurve equ 0123h
    PropertyTagT4Option equ 0124h
    PropertyTagT6Option equ 0125h
    PropertyTagResolutionUnit equ 0128h; Unit of X and Y resolution

    PropertyTagPageNumber equ 0129h
    PropertyTagTransferFuncition equ 012Dh
    PropertyTagSoftwareUsed equ 0131h
    PropertyTagDateTime equ 0132h
    PropertyTagArtist equ 013Bh
    PropertyTagHostComputer equ 013Ch
    PropertyTagPredictor equ 013Dh
    PropertyTagWhitePoint equ 013Eh
    PropertyTagPrimaryChromaticities equ 013Fh
    PropertyTagColorMap equ 0140h
    PropertyTagHalftoneHints equ 0141h
    PropertyTagTileWidth equ 0142h
    PropertyTagTileLength equ 0143h
    PropertyTagTileOffset equ 0144h
    PropertyTagTileByteCounts equ 0145h
    PropertyTagInkSet equ 014Ch
    PropertyTagInkNames equ 014Dh
    PropertyTagNumberOfInks equ 014Eh
    PropertyTagDotRange equ 0150h
    PropertyTagTargetPrinter equ 0151h
    PropertyTagExtraSamples equ 0152h
    PropertyTagSampleFormat equ 0153h
    PropertyTagSMinSampleValue equ 0154h
    PropertyTagSMaxSampleValue equ 0155h
    PropertyTagTransferRange equ 0156h
    PropertyTagJPEGProc equ 0200h
    PropertyTagJPEGInterFormat equ 0201h
    PropertyTagJPEGInterLength equ 0202h
    PropertyTagJPEGRestartInterval equ 0203h
    PropertyTagJPEGLosslessPredictors equ 0205h
    PropertyTagJPEGPointTransforms equ 0206h
    PropertyTagJPEGQTables equ 0207h
    PropertyTagJPEGDCTables equ 0208h
    PropertyTagJPEGACTables equ 0209h
    PropertyTagYCbCrCoefficients equ 0211h
    PropertyTagYCbCrSubsampling equ 0212h
    PropertyTagYCbCrPositioning equ 0213h
    PropertyTagREFBlackWhite equ 0214h
    PropertyTagICCProfile equ 8773h; This TAG is defined by ICC

    ; for embedded ICC in TIFF
    PropertyTagGamma equ 0301h
    PropertyTagICCProfileDescriptor equ 0302h
    PropertyTagSRGBRenderingIntent equ 0303h
    PropertyTagImageTitle equ 0320h
    PropertyTagCopyright equ 8298h
    ; Extra TAGs (Like Adobe Image Information tags etc.)
    PropertyTagResolutionXUnit equ 5001h
    PropertyTagResolutionYUnit equ 5002h
    PropertyTagResolutionXLengthUnit equ 5003h
    PropertyTagResolutionYLengthUnit equ 5004h
    PropertyTagPrintFlags equ 5005h
    PropertyTagPrintFlagsVersion equ 5006h
    PropertyTagPrintFlagsCrop equ 5007h
    PropertyTagPrintFlagsBleedWidth equ 5008h
    PropertyTagPrintFlagsBleedWidthScale equ 5009h
    PropertyTagHalftoneLPI equ 500Ah
    PropertyTagHalftoneLPIUnit equ 500Bh
    PropertyTagHalftoneDegree equ 500Ch
    PropertyTagHalftoneShape equ 500Dh
    PropertyTagHalftoneMisc equ 500Eh
    PropertyTagHalftoneScreen equ 500Fh
    PropertyTagJPEGQuality equ 5010h
    PropertyTagGridSize equ 5011h
    PropertyTagThumbnailFormat equ 5012h; 1 = JPEG, 0 = RAW RGB

    PropertyTagThumbnailWidth equ 5013h
    PropertyTagThumbnailHeight equ 5014h
    PropertyTagThumbnailColorDepth equ 5015h
    PropertyTagThumbnailPlanes equ 5016h
    PropertyTagThumbnailRawBytes equ 5017h
    PropertyTagThumbnailSize equ 5018h
    PropertyTagThumbnailCompressedSize equ 5019h
    PropertyTagColorTransferFunction equ 501Ah
    PropertyTagThumbnailData equ 501Bh; RAW thumbnail bits in

    ; JPEG format or RGB format
    ; depends on
    ; PropertyTagThumbnailFormat
    ; Thumbnail related TAGs
    PropertyTagThumbnailImageWidth equ 5020h; Thumbnail width

    PropertyTagThumbnailImageHeight equ 5021h; Thumbnail height

    PropertyTagThumbnailBitsPerSample equ 5022h; Number of bits per

    ; component
    PropertyTagThumbnailCompression equ 5023h; Compression Scheme

    PropertyTagThumbnailPhotometricInterp equ 5024h; Pixel composition

    PropertyTagThumbnailImageDescription equ 5025h; Image Tile

    PropertyTagThumbnailEquipMake equ 5026h; Manufacturer of Image

    ; Input equipment
    PropertyTagThumbnailEquipModel equ 5027h; Model of Image input

    ; equipment
    PropertyTagThumbnailStripOffsets equ 5028h; Image data location

    PropertyTagThumbnailOrientation equ 5029h; Orientation of image

    PropertyTagThumbnailSamplesPerPixel equ 502Ah; Number of components

    PropertyTagThumbnailRowsPerStrip equ 502Bh; Number of rows per strip

    PropertyTagThumbnailStripBytesCount equ 502Ch; Bytes per compressed

    ; strip
    PropertyTagThumbnailResolutionX equ 502Dh; Resolution in width

    ; direction
    PropertyTagThumbnailResolutionY equ 502Eh; Resolution in height

    ; direction
    PropertyTagThumbnailPlanarConfig equ 502Fh; Image data arrangement

    PropertyTagThumbnailResolutionUnit equ 5030h; Unit of X and Y

    ; Resolution
    PropertyTagThumbnailTransferFunction equ 5031h; Transfer function

    PropertyTagThumbnailSoftwareUsed equ 5032h; Software used

    PropertyTagThumbnailDateTime equ 5033h; File change date and

    ; time
    PropertyTagThumbnailArtist equ 5034h; Person who created the

    ; image
    PropertyTagThumbnailWhitePoint equ 5035h; White point chromaticity

    PropertyTagThumbnailPrimaryChromaticities equ 5036h
    ; Chromaticities of
    ; primaries
    PropertyTagThumbnailYCbCrCoefficients equ 5037h; Color space transforma-

    ; tion coefficients
    PropertyTagThumbnailYCbCrSubsampling equ 5038h; Subsampling ratio of Y

    ; to C
    PropertyTagThumbnailYCbCrPositioning equ 5039h; Y and C position

    PropertyTagThumbnailRefBlackWhite equ 503Ah; Pair of black and white

    ; reference values
    PropertyTagThumbnailCopyRight equ 503Bh; CopyRight holder

    PropertyTagLuminanceTable equ 5090h
    PropertyTagChrominanceTable equ 5091h
    PropertyTagFrameDelay equ 5100h
    PropertyTagLoopCount equ 5101h
    if (GDIPVER ge 0110h)
      PropertyTagGlobalPalette equ 5102h
      PropertyTagIndexBackground equ 5103h
      PropertyTagIndexTransparent equ 5104h
    endif
    ;(GDIPVER >= 0x0110)
    PropertyTagPixelUnit equ 5110h; Unit specifier for pixel/unit

    PropertyTagPixelPerUnitX equ 5111h; Pixels per unit in X

    PropertyTagPixelPerUnitY equ 5112h; Pixels per unit in Y

    PropertyTagPaletteHistogram equ 5113h; Palette histogram

    ; EXIF specific tag
    PropertyTagExifExposureTime equ 829Ah
    PropertyTagExifFNumber equ 829Dh
    PropertyTagExifExposureProg equ 8822h
    PropertyTagExifSpectralSense equ 8824h
    PropertyTagExifISOSpeed equ 8827h
    PropertyTagExifOECF equ 8828h
    PropertyTagExifVer equ 9000h
    PropertyTagExifDTOrig equ 9003h; Date & time of original

    PropertyTagExifDTDigitized equ 9004h; Date & time of digital data generation

    PropertyTagExifCompConfig equ 9101h
    PropertyTagExifCompBPP equ 9102h
    PropertyTagExifShutterSpeed equ 9201h
    PropertyTagExifAperture equ 9202h
    PropertyTagExifBrightness equ 9203h
    PropertyTagExifExposureBias equ 9204h
    PropertyTagExifMaxAperture equ 9205h
    PropertyTagExifSubjectDist equ 9206h
    PropertyTagExifMeteringMode equ 9207h
    PropertyTagExifLightSource equ 9208h
    PropertyTagExifFlash equ 9209h
    PropertyTagExifFocalLength equ 920Ah
    PropertyTagExifSubjectArea equ 9214h; exif 2.2 Subject Area

    PropertyTagExifMakerNote equ 927Ch
    PropertyTagExifUserComment equ 9286h
    PropertyTagExifDTSubsec equ 9290h; Date & Time subseconds

    PropertyTagExifDTOrigSS equ 9291h; Date & Time original subseconds

    PropertyTagExifDTDigSS equ 9292h; Date & TIme digitized subseconds

    PropertyTagExifFPXVer equ 0A000h
    PropertyTagExifColorSpace equ 0A001h
    PropertyTagExifPixXDim equ 0A002h
    PropertyTagExifPixYDim equ 0A003h
    PropertyTagExifRelatedWav equ 0A004h; related sound file

    PropertyTagExifInterop equ 0A005h
    PropertyTagExifFlashEnergy equ 0A20Bh
    PropertyTagExifSpatialFR equ 0A20Ch; Spatial Frequency Response

    PropertyTagExifFocalXRes equ 0A20Eh; Focal Plane X Resolution

    PropertyTagExifFocalYRes equ 0A20Fh; Focal Plane Y Resolution

    PropertyTagExifFocalResUnit equ 0A210h; Focal Plane Resolution Unit

    PropertyTagExifSubjectLoc equ 0A214h
    PropertyTagExifExposureIndex equ 0A215h
    PropertyTagExifSensingMethod equ 0A217h
    PropertyTagExifFileSource equ 0A300h
    PropertyTagExifSceneType equ 0A301h
    PropertyTagExifCfaPattern equ 0A302h
    ; New EXIF 2.2 properties
    PropertyTagExifCustomRendered equ 0A401h
    PropertyTagExifExposureMode equ 0A402h
    PropertyTagExifWhiteBalance equ 0A403h
    PropertyTagExifDigitalZoomRatio equ 0A404h
    PropertyTagExifFocalLengthIn35mmFilm equ 0A405h
    PropertyTagExifSceneCaptureType equ 0A406h
    PropertyTagExifGainControl equ 0A407h
    PropertyTagExifContrast equ 0A408h
    PropertyTagExifSaturation equ 0A409h
    PropertyTagExifSharpness equ 0A40Ah
    PropertyTagExifDeviceSettingDesc equ 0A40Bh
    PropertyTagExifSubjectDistanceRange equ 0A40Ch
    PropertyTagExifUniqueImageID equ 0A420h
    PropertyTagGpsVer equ 0000h
    PropertyTagGpsLatitudeRef equ 0001h
    PropertyTagGpsLatitude equ 0002h
    PropertyTagGpsLongitudeRef equ 0003h
    PropertyTagGpsLongitude equ 0004h
    PropertyTagGpsAltitudeRef equ 0005h
    PropertyTagGpsAltitude equ 0006h
    PropertyTagGpsGpsTime equ 0007h
    PropertyTagGpsGpsSatellites equ 0008h
    PropertyTagGpsGpsStatus equ 0009h
    PropertyTagGpsGpsMeasureMode equ 00Ah
    PropertyTagGpsGpsDop equ 000Bh; Measurement precision

    PropertyTagGpsSpeedRef equ 000Ch
    PropertyTagGpsSpeed equ 000Dh
    PropertyTagGpsTrackRef equ 000Eh
    PropertyTagGpsTrack equ 000Fh
    PropertyTagGpsImgDirRef equ 0010h
    PropertyTagGpsImgDir equ 0011h
    PropertyTagGpsMapDatum equ 0012h
    PropertyTagGpsDestLatRef equ 0013h
    PropertyTagGpsDestLat equ 0014h
    PropertyTagGpsDestLongRef equ 0015h
    PropertyTagGpsDestLong equ 0016h
    PropertyTagGpsDestBearRef equ 0017h
    PropertyTagGpsDestBear equ 0018h
    PropertyTagGpsDestDistRef equ 0019h
    PropertyTagGpsDestDist equ 001Ah
    PropertyTagGpsProcessingMethod equ 001Bh
    PropertyTagGpsAreaInformation equ 001Ch
    PropertyTagGpsDate equ 001Dh
    PropertyTagGpsDifferential equ 001Eh
    if _MSC_VER ge 1200
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
