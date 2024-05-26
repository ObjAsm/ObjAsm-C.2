;Include file created by h2inc+ version C.2.0 on (UTC) 26/05/2024 13:31:25
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\driverspecs.h
;             Created on (UTC) 22/05/2024 17:57:06
;             Last modified on (UTC) 21/02/2024 18:13:46

ifndef DRIVERSPECS_H
  DRIVERSPECS_H equ <>
  ifndef SPECSTRINGS_H
    include specstrings.inc
  endif
  include sdv_driverspecs.inc
  include concurrencysal.inc
  if _MSC_VER gt 1000
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if (_MSC_VER ge 1000) and  not Defined(__midl) and Defined(_PREFAST_) and Defined(_MSC_EXTENSIONS)
    ;[...]
  else
    __internal_kernel_driver equ <>
    __kernel_code equ <>
    __kernel_driver equ <>
    __user_driver equ <>
    __user_code equ <>
    __drv_Mode_impl macro x
      exitm <>
    endm
    __drv_WDM equ <>
    __drv_KMDF equ <>
    __drv_NDIS equ <>
    __prefast_operator_new_throws equ <>
    __prefast_operator_new_null equ <>
    _Analysis_assume_section_locked_ macro name_
      exitm <>
    endm
    _Analysis_assume_section_unlocked_ macro name_
      exitm <>
    endm
  endif
  _IRQL_limited_to_ macro level
    exitm <ASSERT (KeGetCurrentIrql () <= level) ; _Analysis_assume_(KeGetCurrentIrql () <= level) ;>
  endm
  __drv_deref macro annotes
    exitm <__deref _Group_(annotes _SAL_nop_impl_)>
  endm
  __drv_in macro annotes
    exitm <_Pre_ _Group_(annotes _SAL_nop_impl_)>
  endm
  __drv_in_deref macro annotes
    exitm <_Pre_ __deref _Group_(annotes _SAL_nop_impl_)>
  endm
  __drv_out macro annotes
    exitm <_Post_ _Group_(annotes _SAL_nop_impl_)>
  endm
  __drv_out_deref macro annotes
    exitm <_Post_ __deref _Group_(annotes _SAL_nop_impl_)>
  endm
  __drv_when macro cond, annotes
    exitm <_When_(cond, annotes _SAL_nop_impl_)>
  endm
  __drv_at macro expr, annotes
    exitm <_At_(expr, annotes _SAL_nop_impl_)>
  endm
  __drv_fun macro annotes
    exitm <_At_(return, annotes _SAL_nop_impl_)>
  endm
  __drv_ret macro annotes
    exitm <_At_(return, annotes _SAL_nop_impl_)>
  endm
  __drv_arg macro expr, annotes
    exitm <_At_(expr, annotes)>
  endm
  __drv_unit macro p
    exitm <typedef int ___drv_unit_ ## p __GENSYM(__prefast_flag_kernel_driver_mode) ;>
  endm
  ___drv_unit_internal_kernel_driver equ <_SAL_L_Source_(__drv_unit_internal_kernel_driver,, _SA_annotes0(SAL_internal_kernel_driver))>
  ___drv_unit_kernel_code equ <_SAL_L_Source_(___drv_unit_kernel_code,, _SA_annotes0(SAL_kernel) _SA_annotes0(SAL_nodriver))>
  ___drv_unit_kernel_driver equ <_SAL_L_Source_(___drv_unit_kernel_driver,, _SA_annotes0(SAL_kernel) _SA_annotes0(SAL_driver))>
  ___drv_unit_user_driver equ <_SAL_L_Source_(___drv_unit_user_driver,, _SA_annotes0(SAL_nokernel) _SA_annotes0(SAL_driver))>
  ___drv_unit_user_code equ <_SAL_L_Source_(___drv_unit_user_code,, _SA_annotes0(SAL_nokernel) _SA_annotes0(SAL_nodriver))>
  ifndef __internal_kernel_driver
    __internal_kernel_driver equ <__drv_unit(internal_kernel_driver)>
    __kernel_code equ <__drv_unit(kernel_code)>
    __kernel_driver equ <__drv_unit(kernel_driver)>
    __user_driver equ <__drv_unit(user_driver)>
    __user_code equ <__drv_unit(user_code)>
  endif
  __drv_defined macro x
    exitm <_Macro_defined_ (# x)>
  endm
  __drv_functionClass macro x
    exitm <_SAL1_Source_(__drv_functionClass, (x), _Function_class_(x))>
  endm
  _Kernel_acquires_resource_ macro kind
    exitm <_SAL2_Source_(_Kernel_acquires_resource_, (# kind), _Post_ _SA_annotes1(SAL_acquire, # kind))>
  endm
  __drv_acquiresResource macro kind
    exitm <_SAL1_1_Source_(__drv_acquiresResource, (kind), _Acquires_lock_(_Curr_))>
  endm
  _Kernel_releases_resource_ macro kind
    exitm <_SAL2_Source_(_Kernel_releases_resource_, (# kind), _Post_ _SA_annotes1(SAL_release, # kind))>
  endm
  __drv_releasesResource macro kind
    exitm <_SAL1_1_Source_(__drv_releasesResource, (kind), _Releases_lock_(_Curr_))>
  endm
  __drv_innerAcquiresGlobal macro kind, param
    exitm <_SAL1_1_Source_(_drv_innerAcquiresGlobal, (# kind, param\t), _Post_ _SA_annotes2(SAL_acquireGlobal, # kind, param\t))>
  endm
  __drv_acquiresResourceGlobal macro kind, param
    exitm <_SAL1_1_Source_(__drv_acquiresResourceGlobal, (kind, param), _Acquires_lock_(param))>
  endm
  __drv_innerReleasesGlobal macro kind, param
    exitm <_SAL1_1_Source_(__drv_InnerReleasesGlobal, (# kind, param\t), _Post_ _SA_annotes2(SAL_releaseGlobal, # kind, param\t))>
  endm
  __drv_releasesResourceGlobal macro kind, param
    exitm <_SAL1_1_Source_(__drv_releasesResourceGlobal, (kind, param), _Releases_lock_(param))>
  endm
  _Kernel_requires_resource_held_ macro kind
    exitm <_SAL2_Source_(_Kernel_requires_resource_held_, (# kind), _Pre_ _SA_annotes1(SAL_mustHold, # kind))>
  endm
  __drv_mustHold macro kind
    exitm <_SAL_L_Source_(_drv_mustHold, (kind), _When_(! _Arg_comp_ (# kind, "Memory"), _Requires_lock_held_(_Curr_)) _When_(_Arg_comp_ (# kind, "Memory"), _Kernel_requires_resource_held_(kind)))>
  endm
  __drv_innerMustHoldGlobal macro kind, param
    exitm <_SAL_L_Source_(__drv_innerMustHoldGlobal, (# kind, param\t), _Pre_ _SA_annotes2(SAL_mustHoldGlobal, # kind, param\t))>
  endm
  __drv_mustHoldGlobal macro kind, param
    exitm <_SAL1_1_Source_(__drv_mustHoldGlobal, (kind, param), _Requires_lock_held_(param))>
  endm
  _Kernel_requires_resource_not_held_ macro kind
    exitm <_SAL2_Source_(_Kernel_requires_resource_not_held_, (# kind), _Pre_ _SA_annotes1(SAL_neverHold, # kind))>
  endm
  __drv_neverHold macro kind
    exitm <_SAL1_1_Source_(__drv_neverHold, (kind), _Requires_lock_not_held_(_Curr_))>
  endm
  __drv_innerNeverHoldGlobal macro kind, param
    exitm <_SAL_L_Source_(__drv_innterNeverHoldGlobal, (# kind, param\t), _Pre_ _SA_annotes2(SAL_neverHoldGlobal, # kind, param\t))>
  endm
  __drv_neverHoldGlobal macro kind, param
    exitm <_SAL1_1_Source_(__drv_neverHoldGlobal, (kind, param), _Requires_lock_not_held_(param))>
  endm
  __drv_setsIRQL macro irql
    exitm <>
  endm
  _IRQL_raises_ macro irql
    exitm <>
  endm
  __drv_raisesIRQL equ <_SAL1_1_Source_(__drv_raisesIRQL,, _IRQL_raises_)>
  _IRQL_requires_ macro irql
    exitm <>
  endm
  __drv_requiresIRQL macro irql
    exitm <_SAL1_1_Source_(__drv_requiresIRQL, (irql), _IRQL_requires_(irql))>
  endm
  _IRQL_requires_max_ macro irql
    exitm <>
  endm
  __drv_maxIRQL macro irql
    exitm <_SAL1_1_Source_(__drv_maxIRQL, (irql), _IRQL_requires_max_(irql))>
  endm
  _IRQL_requires_min_ macro irql
    exitm <>
  endm
  __drv_minIRQL macro irql
    exitm <_SAL1_1_Source_(__drv_minIRQL, (irql), _IRQL_requires_min_(irql))>
  endm
  _IRQL_saves_ equ <>
  __drv_savesIRQL equ <_SAL1_1_Source_(__drv_savesIRQL,, _IRQL_saves_)>
  _IRQL_saves_global_ macro kind, param
    exitm <>
  endm
  __drv_savesIRQLGlobal macro kind, param
    exitm <_SAL1_1_Source_(__drv_savesIRQLGlobal, (kind, param), _IRQL_saves_global_(kind, param))>
  endm
  _IRQL_restores_ equ <>
  __drv_restoresIRQL equ <_SAL1_1_Source_(__drv_restoresIRQL,, _IRQL_restores_)>
  _IRQL_restores_global_ macro kind, param
    exitm <>
  endm
  __drv_restoresIRQLGlobal macro kind, param
    exitm <_SAL1_1_Source_(__drv_restoresIRQLGlobal, (kind, param), _IRQL_restores_global_(kind, param))>
  endm
  _IRQL_always_function_min_ macro irql
    exitm <>
  endm
  __drv_minFunctionIRQL macro irql
    exitm <_SAL1_1_Source_(__drv_minFunctionIRQL, (irql), _IRQL_always_function_min_(irql))>
  endm
  _IRQL_always_function_max_ macro irql
    exitm <>
  endm
  __drv_maxFunctionIRQL macro irql
    exitm <_SAL1_1_Source_(__drv_maxFunctionIRQL, (irql), _IRQL_always_function_max_(irql))>
  endm
  _IRQL_requires_same_ equ <>
  __drv_sameIRQL equ <_SAL1_1_Source_(__drv_sameIRQL,, _IRQL_requires_same_)>
  _IRQL_uses_cancel_ equ <>
  __drv_useCancelIRQL equ <_SAL1_1_Source_(__drv_usesCancelIRQL,, _IRQL_uses_cancel_)>
  _IRQL_inout_ equ <_IRQL_saves_ _IRQL_restores_>
  _Kernel_clear_do_init_ macro yesNo
    exitm <_SAL2_Source_(_Kernel_clear_do_init_, (yesNo), _Post_ _SA_annotes1(SAL_clearDoInit, yesNo))>
  endm
  __drv_clearDoInit macro yesNo
    exitm <_SAL1_1_Source_(__drv_clearDoInit, (yesNo), _Kernel_clear_do_init_(yesNo))>
  endm
  _Kernel_IoGetDmaAdapter_ equ <_SAL2_Source_(_Kernel_IoGetDmaAdapter_,, _Post_ _SA_annotes0(SAL_IoGetDmaAdapter))>
  __drv_IoGetDmaAdapter equ <_SAL1_1_Source_(__drv_IoGetDmaAdapter,, _Kernel_IoGetDmaAdapter_)>
  __drv_valueIs macro arglist
    exitm <_SAL1_1_Source_(__drv_valueIs, (arglist), _Post_ _SA_annotes1(SAL_return, arglist))>
  endm
  __drv_constant equ <_SAL1_1_Source_(__drv_constant,, _Literal_)>
  __drv_nonConstant equ <_SAL1_1_Source_(__drv_nonConstant,, _Notliteral_)>
  __drv_strictTypeMatch macro mode
    exitm <_SAL1_1_Source_(__drv_strictTypeMatch, (mode), _Pre_ _SA_annotes1(SAL_strictTypeMatch, mode))>
  endm
  __drv_strictType macro typename, mode
    exitm <_SAL1_1_Source_(__drv_strictType, (typename, mode), _Pre_ _SA_annotes2(SAL_strictType, typename, mode))>
  endm
  __drv_typeConst equ 0
  __drv_typeCond equ 1
  __drv_typeBitset equ 2
  __drv_typeExpr equ 3
  __drv_notPointer equ <_SAL1_1_Source_(__drv_notPointer,, _Pre_ _SA_annotes1(SAL_mayBePointer, __no))>
  __drv_isObjectPointer equ <_SAL1_1_Source_(__drv_isObjectPointer,, _Points_to_data_)>
  __drv_aliasesMem equ <_SAL_L_Source_(__drv_aliasesMem,, _Post_ _SA_annotes0(SAL_IsAliased))>
  __drv_allocatesMem macro kind
    exitm <_SAL_L_Source_(__drv_allocatesMem, (kind), _Post_ _SA_annotes1(SAL_NeedsRelease, __yes))>
  endm
  __drv_freesMem macro kind
    exitm <_SAL_L_Source_(__drv_freesMem, (kind), _Post_ _SA_annotes1(SAL_NeedsRelease, __no))>
  endm
  __drv_preferredFunction macro func, why
    exitm <_SAL_L_Source_(__drv_preferredFunction, (func, why), _Pre_ _SA_annotes2(SAL_preferredFunction, func, why))>
  endm
  __drv_reportError macro why
    exitm <_SAL_L_Source_(__drv_reportError, (why), _Pre_ _SA_annotes1(SAL_error, why))>
  endm
  _Kernel_float_saved_ equ <_SAL2_Source_(_Kernel_float_saved_,, _Post_ _SA_annotes0(SAL_floatSaved))>
  __drv_floatSaved equ <_SAL1_1_Source_(__drv_floatSaved,, _Kernel_float_saved_)>
  _Kernel_float_restored_ equ <_SAL2_Source_(_Kernel_float_restored_,, _Post_ _SA_annotes0(SAL_floatRestored))>
  __drv_floatRestored equ <_SAL1_1_Source_(__drv_floatRestored,, _Kernel_float_restored_)>
  _Kernel_float_used_ equ <_SAL2_Source_(_Kernel_float_used_,, _Post_ _SA_annotes0(SAL_floatUsed))>
  __drv_floatUsed equ <_SAL1_1_Source_(__drv_floatUsed,, _Kernel_float_used_)>
  __drv_interlocked equ <_SAL1_1_Source_(__drv_interlocked,, _Interlocked_operand_)>
  __drv_inTry equ <_SAL_L_Source_(__drv_inTry,, _Pre_ _SA_annotes1(SAL_inTry, __yes))>
  __drv_notInTry equ <_SAL_L_Source_(__drv_notInTry,, _Pre_ _SA_annotes1(SAL_inTry, __no))>
  __drv_formatString macro kind
    exitm <_SAL1_1_Source_(__drv_formatString, (kind), _SA_annotes1(SAL_IsFormatString, # kind))>
  endm
  _Dispatch_type_ macro x
    exitm <_SAL2_Source_(Dispatch_type_, (x), _SA_annotes1(SAL_functionClassNew, # x))>
  endm
  __drv_dispatchType macro x
    exitm <_SAL1_1_Source_(__drv_displatchType, (x), _SA_annotes1(SAL_functionClassNew, # x))>
  endm
  __drv_dispatchType_other equ <_SAL1_1_Source_(__drv_dispatchType_other,, __drv_dispatchType(IRP_MJ_OTHER))>
  __drv_completionType macro kindlist
    exitm <_SAL1_1_Source_(__drv_completionType, (kindlist), _SA_annotes1(SAL_completionType, # kindlist))>
  endm
  __drv_callbackType macro kind
    exitm <_SAL1_1_Source_(__drv_callbackType, (kind), _SA_annotes1(SAL_callbackType, # kind))>
  endm
  ifdef _PREFAST_
    ;[...]
  else
    __drv_acquiresExclusiveResource macro kind
      exitm <>
    endm
    __drv_releasesExclusiveResource macro kind
      exitm <>
    endm
    __drv_acquiresExclusiveResourceGlobal macro kind, param
      exitm <>
    endm
    __drv_releasesExclusiveResourceGlobal macro kind, param
      exitm <>
    endm
    __drv_acquiresCancelSpinLock equ <>
    __drv_releasesCancelSpinLock equ <>
    __drv_mustHoldCancelSpinLock equ <>
    __drv_holdsCancelSpinLock macro 
      exitm <>
    endm
    __drv_neverHoldCancelSpinLock equ <>
    __drv_acquiresCriticalRegion equ <>
    __drv_releasesCriticalRegion equ <>
    __drv_mustHoldCriticalRegion equ <>
    __drv_neverHoldCriticalRegion equ <>
    __drv_holdsCriticalRegion macro 
      exitm <>
    endm
    __drv_acquiresPriorityRegion equ <>
    __drv_releasesPriorityRegion equ <>
    __drv_mustHoldPriorityRegion equ <>
    __drv_neverHoldPriorityRegion equ <>
    __drv_holdsPriorityRegion macro 
      exitm <>
    endm
  endif
  _IRQL_is_cancel_ equ <>
  __drv_isCancelIRQL equ <_IRQL_is_cancel_>
  ifdef __cplusplus
    ;[...]
  endif
endif
