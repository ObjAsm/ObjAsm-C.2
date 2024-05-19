;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\gdipluseffects.h\gdipluseffects.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:10

ifndef _GDIPLUSEFFECTS_HPP
  _GDIPLUSEFFECTS_HPP equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if (GDIPVER ge 0110h)
      SharpenParams struct
        radius REAL4 ?
        amount REAL4 ?
      SharpenParams ends
      BlurParams struct
        radius REAL4 ?
        expandEdge BOOL ?
      BlurParams ends
      BrightnessContrastParams struct
        brightnessLevel INT_ ?
        contrastLevel INT_ ?
      BrightnessContrastParams ends
      RedEyeCorrectionParams struct
        numberOfAreas UINT ?
        areas POINTER ?
      RedEyeCorrectionParams ends
      HueSaturationLightnessParams struct
        hueLevel INT_ ?
        saturationLevel INT_ ?
        lightnessLevel INT_ ?
      HueSaturationLightnessParams ends
      TintParams struct
        hue INT_ ?
        amount INT_ ?
      TintParams ends
      LevelsParams struct
        highlight INT_ ?
        midtone INT_ ?
        shadow INT_ ?
      LevelsParams ends
      ColorBalanceParams struct
        cyanRed INT_ ?
        magentaGreen INT_ ?
        yellowBlue INT_ ?
      ColorBalanceParams ends
      ColorLUTParams struct
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
        adjustValue INT_ ?
      ColorCurveParams ends
      ifndef _GDIPLUSEFFECTS_EXCLUDEOBJECTS
      endif
    endif
  endif
endif
