;Include file created by h2incX, Version B.01.01, 01/10/2012 08:50
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\kernelspecs.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifndef KERNELSPECS_H
  KERNELSPECS_H equ <>
  include DriverSpecs.inc
  if _MSC_VER gt 1000
  endif
  ifdef __cplusplus
    ;[...]
  endif
  DISPATCH_LEVEL equ 2
  APC_LEVEL equ 1
  PASSIVE_LEVEL equ 0
  if Defined(_X86_)
    HIGH_LEVEL equ 31
  endif
  if Defined(_AMD64_)
    HIGH_LEVEL equ 15
  endif
  if Defined(_ARM_)
    ;[...]
  endif
  if Defined(_IA64_)
    HIGH_LEVEL equ 15
  endif
  if Defined(_ARM64_)
    ;[...]
  endif
  __drv_setsIRQL macro irql
    exitm <_SAL1_Source_(__drv_setsIRQL,, _Post_ _SA_annotes1(SAL_IRQL, irql))>
  endm
  _IRQL_raises_ macro irql
    exitm <_SAL2_Source_(_IRQL_raises_,, _Post_ _SA_annotes1(SAL_raiseIRQL, irql))>
  endm
  __drv_raisesIRQL_ macro irql
    exitm <_SAL1_Source_(__drv_raisesIRQL,, _IRQL_raises_(irql))>
  endm
  _IRQL_requires_ macro irql
    exitm <_SAL2_Source_(_IRQL_requires_, (irql), _Pre_ _SA_annotes1(SAL_IRQL, irql))>
  endm
  __drv_requiresIRQL macro irql
    exitm <_SAL1_Source_(__drv_requiresIRQL,, _IRQL_requires_(irql))>
  endm
  _IRQL_requires_max_ macro irql
    exitm <_SAL2_Source_(_IRQL_requires_max_, (irql), _Pre_ _SA_annotes1(SAL_maxIRQL, irql))>
  endm
  __drv_maxIRQL macro irql
    exitm <_SAL1_Source_(__drv_maxIRQL,, _IRQL_requires_max_(irql))>
  endm
  _IRQL_requires_min_ macro irql
    exitm <_SAL2_Source_(_IRQL_requires_min_, (irql), _Pre_ _SA_annotes1(SAL_minIRQL, irql))>
  endm
  __drv_minIRQL macro irql
    exitm <_SAL1_Source_(__drv_minIRQL,, _IRQL_requires_min_(irql))>
  endm
  _IRQL_saves_ equ <_SAL2_Source_(_IRQL_saves_,, _Post_ _SA_annotes0(SAL_saveIRQL))>
  __drv_savesIRQL equ <_SAL1_Source_(__drv_savesIRQL,, _IRQL_saves_)>
  _IRQL_saves_global_ macro kind, param
    exitm <_SAL2_Source_(_IRQL_saves_global_, (kind, param), _Post_ _SA_annotes2(SAL_saveIRQLGlobal, # kind, param\t))>
  endm
  __drv_savesIRQLGlobal macro kind, param
    exitm <_SAL1_Source_(__drv_savesIRQLGlobal,, _IRQL_saves_global_(kind, param))>
  endm
  _IRQL_restores_ equ <_SAL2_Source_(_IRQL_restores_,, _Post_ _SA_annotes0(SAL_restoreIRQL))>
  __drv_restoresIRQL equ <_SAL1_Source_(__drv_restoresIRQL,, _IRQL_restores_)>
  _IRQL_restores_global_ macro kind, param
    exitm <_SAL2_Source_(_IRQL_restores_global_, (kind, param), _Post_ _SA_annotes2(SAL_restoreIRQLGlobal, # kind, param\t))>
  endm
  __drv_restoresIRQLGlobal macro kind, param
    exitm <_SAL1_Source_(__drv_restoresIRQLGlobal,, _IRQL_restores_global_(kind, param))>
  endm
  _IRQL_always_function_min_ macro irql
    exitm <_SAL2_Source_(_IRQL_always_function_min_, (irql), _Pre_ _SA_annotes1(SAL_minFunctionIrql, irql))>
  endm
  __drv_minFunctionIRQL macro irql
    exitm <_SAL1_Source_(__drv_minFunctionIRQL,, _IRQL_always_function_min_(irql))>
  endm
  _IRQL_always_function_max_ macro irql
    exitm <_SAL2_Source_(_IRQL_always_function_max_, (irql), _Pre_ _SA_annotes1(SAL_maxFunctionIrql, irql))>
  endm
  __drv_maxFunctionIRQL macro irql
    exitm <_SAL1_Source_(__drv_maxFunctionIRQL,, _IRQL_always_function_max_(irql))>
  endm
  _IRQL_requires_same_ equ <_SAL2_Source_(_IRQL_requires_same_,, _Post_ _SA_annotes0(SAL_sameIRQL))>
  __drv_sameIRQL equ <_SAL1_Source_(__drv_sameIRQL,, _IRQL_requires_same_)>
  _IRQL_uses_cancel_ equ <_SAL2_Source_(_IRQL_uses_cancel_,, _Post_ _SA_annotes0(SAL_UseCancelIrql))>
  __drv_useCancelIRQL equ <_SAL1_Source_(__drv_useCancelIRQL,, _IRQL_uses_cancel_)>
  _IRQL_inout_ equ <_IRQL_saves_ _IRQL_restores_>
  ifdef _PREFAST_
    ;[...]
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

