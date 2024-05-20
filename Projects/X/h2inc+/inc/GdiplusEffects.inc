;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdipluseffects.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:10

;**************************************************************************
ifndef _GDIPLUSEFFECTS_HPP
  _GDIPLUSEFFECTS_HPP equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (GDIPVER ge 0110h)
      ;-----------------------------------------------------------------------------
      ; GDI+ effect GUIDs
      ;-----------------------------------------------------------------------------
      ; {633C80A4-1843-482b-9EF2-BE2834C5FDD4}
      ; {63CBF3EE-C526-402c-8F71-62C540BF5142}
      ; {718F2615-7933-40e3-A511-5F68FE14DD74}
      ; {A7CE72A9-0F7F-40d7-B3CC-D0C02D5C3212}
      ; {D3A1DBE1-8EC4-4c17-9F4C-EA97AD1C343D}
      ; {8B2DD6C3-EB07-4d87-A5F0-7108E26A9C5F}
      ; {99C354EC-2A31-4f3a-8C34-17A803B33A25}
      ; {1077AF00-2848-4441-9489-44AD4C2D7A2C}
      ; {537E597D-251E-48da-9664-29CA496B70F8}
      ; {74D29D05-69A4-4266-9549-3CC52836B632}
      ; {DD6A0022-58E4-4a67-9D9B-D48EB881A53D}
      ;-----------------------------------------------------------------------------
      SharpenParams struct
        radius REAL4 ?
        amount REAL4 ?
      SharpenParams ends
      BlurParams struct
        radius REAL4 ?
        expandEdge DWORD ?
      BlurParams ends
      BrightnessContrastParams struct
        brightnessLevel SDWORD ?
        contrastLevel SDWORD ?
      BrightnessContrastParams ends
      RedEyeCorrectionParams struct
        numberOfAreas DWORD ?
        areas POINTER ?
      RedEyeCorrectionParams ends
      HueSaturationLightnessParams struct
        hueLevel SDWORD ?
        saturationLevel SDWORD ?
        lightnessLevel SDWORD ?
      HueSaturationLightnessParams ends
      TintParams struct
        hue SDWORD ?
        amount SDWORD ?
      TintParams ends
      LevelsParams struct
        highlight SDWORD ?
        midtone SDWORD ?
        shadow SDWORD ?
      LevelsParams ends
      ColorBalanceParams struct
        cyanRed SDWORD ?
        magentaGreen SDWORD ?
        yellowBlue SDWORD ?
      ColorBalanceParams ends
      ColorLUTParams struct
        ; look up tables for each color channel.
        lutB ColorChannelLUT ?
        lutG ColorChannelLUT ?
        lutR ColorChannelLUT ?
        lutA ColorChannelLUT ?
      ColorLUTParams ends
      CurveAdjustments typedef SDWORD
      AdjustExposure equ 0
      AdjustDensity equ 1
      AdjustContrast equ 2
      AdjustHighlight equ 3
      AdjustShadow equ 4
      AdjustMidtone equ 5
      AdjustWhiteSaturation equ 6
      AdjustBlackSaturation equ 7

      CurveChannel typedef SDWORD
      CurveChannelAll equ 0
      CurveChannelRed equ 1
      CurveChannelGreen equ 2
      CurveChannelBlue equ 3

      ColorCurveParams struct
        adjustment CurveAdjustments ?
        channel CurveChannel ?
        adjustValue SDWORD ?
      ColorCurveParams ends
      ifndef _GDIPLUSEFFECTS_EXCLUDEOBJECTS
        ; pvData is allocated by ApplyEffect. Return the pointer so that
        ; it can be freed by the appropriate memory manager.
        ; Release the native Effect.
        ; protected data members.
        ; Blur
        ; constructors cannot return an error code.
        ; Sharpen
        ; RedEye Correction
        ; constructors cannot return an error code.
        ; Brightness/Contrast
        ; Hue/Saturation/Lightness
        ; Highlight/Midtone/Shadow curves
        ; Tint
        ; ColorBalance
        ; ColorMatrix
        ; constructors cannot return an error code.
        ; ColorLUT
        ; constructors cannot return an error code.
        ; Color Curve
      endif
      ; _GDIPLUSEFFECTS_EXCLUDEEOBJECTS
    endif
    ;(GDIPVER >= 0x0110)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
