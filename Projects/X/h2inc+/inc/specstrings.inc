;Include file created by h2inc+ version C.2.0 on (UTC) 26/05/2024 13:31:25
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\specstrings.h
;             Created on (UTC) 22/05/2024 17:57:08
;             Last modified on (UTC) 12/02/2024 17:05:38

ifndef SPECSTRINGS_H
  SPECSTRINGS_H equ <>
  if _MSC_VER
  endif
  if _MSC_VER ge 1200
  endif
  if  not Defined(_SAL_VERSION_SAL2)
    if Defined(__BUILDMACHINE__) or Defined(_USE_SAL2_ONLY)
      _SAL_VERSION_SAL2 macro _A
        exitm <SAL_2_Clean_Violation_using ## _A>
      endm
    else
      _SAL_VERSION_SAL2 macro _A
        exitm <>
      endm
    endif
    ifdef _USE_SAL2_ONLY
      _SAL2_STRICT equ <>
      _SAL_VERSION_CHECK macro _A
        exitm <_SAL_VERSION_SAL2(_A)>
      endm
    else
      _SAL_VERSION_CHECK macro _A
        exitm <>
      endm
    endif
    ifndef SAL_VERSION_CHECK
      SAL_VERSION_CHECK macro _A
        exitm <_SAL_VERSION_CHECK(_A)>
      endm
      SAL_VERSION_SAL2 macro _A
        exitm <_SAL_VERSION_SAL2(_A)>
      endm
    endif
  endif
  ifndef _SAL_L_Source_
    if _USE_ATTRIBUTES_FOR_SAL
      _SAL_L_Source_ macro Name_, args, annotes
        exitm <_SA_annotes3(SAL_name, # Name_,, "2") _Group_(annotes _SAL_nop_impl_)>
      endm
    else
      _SAL_L_Source_ macro Name_, args, annotes
        exitm <_SA_annotes3(SAL_name, # Name_,, "2") _GrouP_(annotes _SAL_nop_impl_)>
      endm
    endif
  endif
  include sal.inc
  ifndef __SAL_H_FULL_VER
    __SAL_H_FULL_VER equ 140050727
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if __SAL_H_FULL_VER le 140050727
    if  not Defined(__midl) and Defined(_PREFAST_) and _MSC_VER ge 1000
      ;[...]
    else
      __inner_bound equ <>
      __inner_range macro lb, ub
        exitm <>
      endm
      __inner_assume_bound_dec equ <>
      __inner_assume_bound macro i
        exitm <>
      endm
      __inner_allocator equ <>
      __static_context macro ctx, annotes
        exitm <>
      endm
      __failure macro x
        exitm <>
      endm
      __valueUndefined equ <>
      __failureDefault macro x
        exitm <>
      endm
    endif
    __xcount macro size_
      exitm <_SAL1_Source_(__xcount, (size_), __notnull __inexpressible_writableTo(size_))>
    endm
    __in_xcount macro size_
      exitm <_SAL1_Source_(__in_xcount, (size_), __in _Pre_ __inexpressible_readableTo(size_))>
    endm
    __out_xcount macro size_
      exitm <_SAL1_Source_(__out_xcount, (size_), __xcount(size_) _Post_ __valid __refparam)>
    endm
    __out_xcount_part macro size_, length_
      exitm <_SAL1_Source_(__out_xcount_part_, (size_, length_), __out_xcount(size_) _Post_ __inexpressible_readableTo(length_))>
    endm
    __out_xcount_full macro size_
      exitm <_SAL1_Source_(__out_xcount_full, (size_), __out_xcount_part(size_, size_))>
    endm
    __inout_xcount macro size_
      exitm <_SAL1_Source_(__inout_xcount, (size_), __out_xcount(size_) _Pre_ __valid)>
    endm
    __inout_xcount_part macro size_, length_
      exitm <_SAL1_Source_(__inout_xcount_part, (size_, length_), __out_xcount_part(size_, length_) _Pre_ __valid _Pre_ __inexpressible_readableTo(length_))>
    endm
    __inout_xcount_full macro size_
      exitm <_SAL1_Source_(__inout_xcount_full, (size_), __inout_xcount_part(size_, size_))>
    endm
    __xcount_opt macro size_
      exitm <_SAL1_Source_(__xcount_opt, (size_), __xcount(size_) __exceptthat __maybenull)>
    endm
    __in_xcount_opt macro size_
      exitm <_SAL1_Source_(__in_xcount_opt, (size_), __in_xcount(size_) __exceptthat __maybenull)>
    endm
    __out_xcount_opt macro size_
      exitm <_SAL1_Source_(__out_xcount_opt, (size_), __out_xcount(size_) __exceptthat __maybenull)>
    endm
    __out_xcount_part_opt macro size_, length_
      exitm <_SAL1_Source_(__out_xcount_part_opt, (size_, length_), __out_xcount_part(size_, length_) __exceptthat __maybenull)>
    endm
    __out_xcount_full_opt macro size_
      exitm <_SAL1_Source_(__out_xcount_full_opt, (size_), __out_xcount_full(size_) __exceptthat __maybenull)>
    endm
    __inout_xcount_opt macro size_
      exitm <_SAL1_Source_(__inout_xcount_opt, (size_), __inout_xcount(size_) __exceptthat __maybenull)>
    endm
    __inout_xcount_part_opt macro size_, length_
      exitm <_SAL1_Source_(__inout_xcount_part_opt, (size_, length_), __inout_xcount_part(size_, length_) __exceptthat __maybenull)>
    endm
    __inout_xcount_full_opt macro size_
      exitm <_SAL1_Source_(__inout_xcount_full_opt, (size_), __inout_xcount_full(size_) __exceptthat __maybenull)>
    endm
    __deref_xcount macro size_
      exitm <_SAL1_Source_(__deref_xcount, (size_), __ecount(1) _Post_ __elem_readableTo(1) _Post_ __deref __notnull _Post_ __deref __inexpressible_writableTo(size_))>
    endm
    __deref_in equ <_SAL1_Source_(__deref_in,, __in _Pre_ __deref __deref __readonly)>
    __deref_in_ecount macro size_
      exitm <_SAL1_Source_(__deref_in_ecount, (size_), __deref_in _Pre_ __deref __elem_readableTo(size_))>
    endm
    __deref_in_bcount macro size_
      exitm <_SAL1_Source_(__deref_in_bcount, (size_), __deref_in _Pre_ __deref __byte_readableTo(size_))>
    endm
    __deref_in_xcount macro size_
      exitm <_SAL1_Source_(__deref_in_xcount, (size_), __deref_in _Pre_ __deref __inexpressible_readableTo(size_))>
    endm
    __deref_out_xcount macro size_
      exitm <_SAL1_Source_(__deref_out_xcount, (size_), __deref_xcount(size_) _Post_ __deref __valid __refparam)>
    endm
    __deref_out_xcount_part macro size_, length_
      exitm <_SAL1_Source_(__deref_out_xcount_part, (size_, length_), __deref_out_xcount(size_) _Post_ __deref __inexpressible_readableTo(length_))>
    endm
    __deref_out_xcount_full macro size_
      exitm <_SAL1_Source_(__deref_out_xcount_full, (size_), __deref_out_xcount_part(size_, size_))>
    endm
    __deref_out_xcount macro size_
      exitm <_SAL1_Source_(__deref_out_xcount, (size_), __deref_xcount(size_) _Post_ __deref __valid __refparam)>
    endm
    __inout_xcount_opt macro size_
      exitm <_SAL1_Source_(__inout_xcount_opt, (size_), __inout_xcount(size_) __exceptthat __maybenull)>
    endm
    __deref_xcount macro size_
      exitm <_SAL1_Source_(__deref_xcount, (size_), __ecount(1) _Post_ __elem_readableTo(1) _Post_ __deref __notnull _Post_ __deref __inexpressible_writableTo(size_))>
    endm
    __deref_in equ <_SAL1_Source_(__deref_in,, __in _Pre_ __deref __deref __readonly)>
    __deref_in_ecount macro size_
      exitm <_SAL1_Source_(__deref_in_ecount, (size_), __deref_in _Pre_ __deref __elem_readableTo(size_))>
    endm
    __deref_in_bcount macro size_
      exitm <_SAL1_Source_(__deref_in_bcount, (size_), __deref_in _Pre_ __deref __byte_readableTo(size_))>
    endm
    __deref_in_xcount macro size_
      exitm <_SAL1_Source_(__deref_in_xcount, (size_), __deref_in _Pre_ __deref __inexpressible_readableTo(size_))>
    endm
    __deref_out_xcount macro size_
      exitm <_SAL1_Source_(__deref_out_xcount, (size_), __deref_xcount(size_) _Post_ __deref __valid __refparam)>
    endm
    __deref_out_xcount_part macro size_, length_
      exitm <_SAL1_Source_(__deref_out_xcount_part, (size_, length_), __deref_out_xcount(size_) _Post_ __deref __inexpressible_readableTo(length_))>
    endm
    __deref_out_xcount_full macro size_
      exitm <_SAL1_Source_(__deref_out_xcount_full, (size_), __deref_out_xcount_part(size_, size_))>
    endm
    __deref_out_xcount macro size_
      exitm <_SAL1_Source_(__deref_out_xcount, (size_), __deref_xcount(size_) _Post_ __deref __valid __refparam)>
    endm
    __deref_inout_xcount macro size_
      exitm <_SAL1_Source_(__deref_inout_xcount, (size_), __deref_inout _Pre_ __deref __inexpressible_writableTo(size_) _Post_ __deref __inexpressible_writableTo(size_))>
    endm
    __deref_inout_xcount_part macro size_, length_
      exitm <_SAL1_Source_(__deref_inout_xcount_part, (size_, length_), __deref_inout_xcount(size_) _Pre_ __deref __inexpressible_readableTo(length_) _Post_ __deref __inexpressible_readableTo(length_))>
    endm
    __deref_inout_xcount_full macro size_
      exitm <_SAL1_Source_(__deref_inout_xcount_full, (size_), __deref_inout_xcount_part(size_, size_))>
    endm
    __deref_xcount_opt macro size_
      exitm <_SAL1_Source_(__deref_xcount_opt, (size_), __deref_xcount(size_) _Post_ __deref __exceptthat __maybenull)>
    endm
    __deref_in_opt equ <_SAL1_Source_(__deref_in_opt,, __deref_in _Pre_ __deref __exceptthat __maybenull)>
    __deref_in_opt_out equ <_SAL1_Source_(__deref_in_opt_out,, __deref_inout _Pre_ __deref __exceptthat __maybenull _Post_ __deref __notnull)>
    __deref_in_ecount_opt macro size_
      exitm <_SAL1_Source_(__deref_in_ecount_opt, (size_), __deref_in_ecount(size_) _Pre_ __deref __exceptthat __maybenull)>
    endm
    __deref_in_bcount_opt macro size_
      exitm <_SAL1_Source_(__deref_in_bcount_opt_, (size_), __deref_in_bcount(size_) _Pre_ __deref __exceptthat __maybenull)>
    endm
    __deref_in_xcount_opt macro size_
      exitm <_SAL1_Source_(__deref_in_xcount_opt, (size_), __deref_in_xcount(size_) _Pre_ __deref __exceptthat __maybenull)>
    endm
    __deref_out_xcount_opt macro size_
      exitm <_SAL1_Source_(__deref_out_xcount_opt, (size_), __deref_out_xcount(size_) _Post_ __deref __exceptthat __maybenull)>
    endm
    __deref_out_xcount_part_opt macro size_, length_
      exitm <_SAL1_Source_(__deref_out_xcount_part_opt, (size_, length_), __deref_out_xcount_part(size_, length_) _Post_ __deref __exceptthat __maybenull)>
    endm
    __deref_out_xcount_full_opt macro size_
      exitm <_SAL1_Source_(__deref_out_xcount_full_opt, (size_), __deref_out_xcount_full(size_) _Post_ __deref __exceptthat __maybenull)>
    endm
    __deref_inout_xcount_opt macro size_
      exitm <_SAL1_Source_(__deref_inout_xcount_opt, (size_), __deref_inout_xcount(size_) _Pre_ __deref __exceptthat __maybenull _Post_ __deref __exceptthat __maybenull)>
    endm
    __deref_inout_xcount_part_opt macro size_, length_
      exitm <_SAL1_Source_(__deref_inout_xcount_part_opt, (size_, length_), __deref_inout_xcount_part(size_, length_) _Pre_ __deref __exceptthat __maybenull _Post_ __deref __exceptthat __maybenull)>
    endm
    __deref_inout_xcount_full_opt macro size_
      exitm <_SAL1_Source_(__deref_inout_xcount_full_opt, (size_), __deref_inout_xcount_full(size_) _Pre_ __deref __exceptthat __maybenull _Post_ __deref __exceptthat __maybenull)>
    endm
    __deref_opt_xcount macro size_
      exitm <_SAL1_Source_(__deref_opt_xcount, (size_), __deref_xcount(size_) __exceptthat __maybenull)>
    endm
    __deref_opt_in equ <_SAL1_Source_(__deref_opt_in,, __deref_in __exceptthat __maybenull)>
    __deref_opt_in_ecount macro size_
      exitm <_SAL1_Source_(__deref_opt_in_ecount, (size_), __deref_in_ecount(size_) __exceptthat __maybenull)>
    endm
    __deref_opt_in_bcount macro size_
      exitm <_SAL1_Source_(__deref_opt_in_bcount, (size_), __deref_in_bcount(size_) __exceptthat __maybenull)>
    endm
    __deref_opt_in_xcount macro size_
      exitm <_SAL1_Source_(__deref_opt_in_xcount, (size_), __deref_in_xcount(size_) __exceptthat __maybenull)>
    endm
    __deref_opt_out_xcount macro size_
      exitm <_SAL1_Source_(__deref_opt_out_xcount, (size_), __deref_out_xcount(size_) __exceptthat __maybenull)>
    endm
    __deref_opt_out_xcount_part macro size_, length_
      exitm <_SAL1_Source_(__deref_opt_out_xcount_part, (size_, length_), __deref_out_xcount_part(size_, length_) __exceptthat __maybenull)>
    endm
    __deref_opt_out_xcount_full macro size_
      exitm <_SAL1_Source_(__deref_opt_out_xcount_full, (size_), __deref_out_xcount_full(size_) __exceptthat __maybenull)>
    endm
    __deref_opt_inout_xcount macro size_
      exitm <_SAL1_Source_(__deref_opt_inout_xcount, (size_), __deref_inout_xcount(size_) __exceptthat __maybenull)>
    endm
    __deref_opt_inout_xcount_part macro size_, length_
      exitm <_SAL1_Source_(__deref_opt_inout_xcount_part, (size_, length_), __deref_inout_xcount_part(size_, length_) __exceptthat __maybenull)>
    endm
    __deref_opt_inout_xcount_full macro size_
      exitm <_SAL1_Source_(__deref_opt_inout_xcount_full, (size_), __deref_inout_xcount_full(size_) __exceptthat __maybenull)>
    endm
    __deref_opt_xcount_opt macro size_
      exitm <_SAL1_Source_(__deref_opt_xcount_opt, (size_), __deref_xcount_opt(size_) __exceptthat __maybenull)>
    endm
    __deref_opt_in_opt equ <_SAL1_Source_(__deref_opt_in_opt,, __deref_in_opt __exceptthat __maybenull)>
    __deref_opt_in_ecount_opt macro size_
      exitm <_SAL1_Source_(__deref_opt_in_ecount_opt, (size_), __deref_in_ecount_opt(size_) __exceptthat __maybenull)>
    endm
    __deref_opt_in_bcount_opt macro size_
      exitm <_SAL1_Source_(__deref_opt_in_bcount_opt, (size_), __deref_in_bcount_opt(size_) __exceptthat __maybenull)>
    endm
    __deref_opt_in_xcount_opt macro size_
      exitm <_SAL1_Source_(__deref_opt_in_xcount_opt, (size_), __deref_in_xcount_opt(size_) __exceptthat __maybenull)>
    endm
    __deref_opt_out_xcount_opt macro size_
      exitm <_SAL1_Source_(__deref_opt_out_xcount_opt, (size_), __deref_out_xcount_opt(size_) __exceptthat __maybenull)>
    endm
    __deref_opt_out_xcount_part_opt macro size_, length_
      exitm <_SAL1_Source_(__deref_opt_out_xcount_part_opt, (size_, length_), __deref_out_xcount_part_opt(size_, length_) __exceptthat __maybenull)>
    endm
    __deref_opt_out_xcount_full_opt macro size_
      exitm <_SAL1_Source_(__deref_opt_out_scount_full_opt, (size_), __deref_out_xcount_full_opt(size_) __exceptthat __maybenull)>
    endm
    __deref_opt_inout_xcount_opt macro size_
      exitm <_SAL1_Source_(__deref_opt_inout_xcount_opt, (size_), __deref_inout_xcount_opt(size_) __exceptthat __maybenull)>
    endm
    __deref_opt_inout_xcount_part_opt macro size_, length_
      exitm <_SAL1_Source_(__deref_inout_xcount_part_opt(size_, (size_, length_), length_) __exceptthat __maybenull)>
    endm
    __deref_opt_inout_xcount_full_opt macro size_
      exitm <_SAL1_Source_(__deref_opt_inout_scount_full_opt, (size_), __deref_inout_xcount_full_opt(size_) __exceptthat __maybenull)>
    endm
    __deref_in_ecount_iterator macro size_, incr
      exitm <_SAL1_Source_(__deref_in_ecount_iterator, (size_, incr), __inout _Pre_ __deref __elem_readableTo(size_) __deref_out_range(==, _Old_ (* _Curr_) + incr))>
    endm
    __deref_out_ecount_iterator macro size_, incr
      exitm <_SAL1_Source_(__deref_out_ecount_iterator, (size_, incr), __inout _Pre_ __deref __elem_writableTo(size_) __deref_out_range(==, _Old_ (* _Curr_) + incr))>
    endm
    __deref_inout_ecount_iterator macro size_, incr
      exitm <_SAL1_Source_(__deref_inout_ecount_iterator, (size_, incr), __inout _Pre_ __deref __elem_readableTo(size_) _Pre_ __deref __elem_writableTo(size_) __deref_out_range(==, _Old_ (* _Curr_) + incr))>
    endm
    __post_bcount macro size_
      exitm <_SAL1_Source_(__post_bcount, (size_), _Post_ __byte_writableTo(size_))>
    endm
    __post_ecount macro size_
      exitm <_SAL1_Source_(__post_ecount, (size_), _Post_ __elem_writableTo(size_))>
    endm
    __deref_realloc_bcount macro insize, outsize
      exitm <_SAL1_Source_(__deref_realloc_bcount, (insize, outsize), __inout _Pre_ __deref __byte_readableTo(insize) _Post_ __deref __byte_writableTo(outsize))>
    endm
    __in_ecount_or_z macro c_
      exitm <_SAL1_Source_(__in_ecount_or_z, (c_), _When_(_String_length_ (_Curr_) < (c_), __in_z) _When_(_String_length_ (_Curr_) >= (c_), __in_ecount(c_)))>
    endm
    __post_nullnullterminated equ <>
    ifndef RC_INVOKED
      __nullnullterminated equ <_SAL1_Source_(__nullnullterminated,, __inexpressible_readableTo("string terminated by two nulls") __nullterminated)>
      __post_nullnullterminated equ <_SAL1_Source_(__post_nullnullterminated,, _Post_ __inexpressible_readableTo("string terminated by two nulls") _Post_ __nullterminated)>
    endif
  endif
  if (_MSC_VER ge 1000) and  not Defined(__midl) and Defined(_PREFAST_)
    ;[...]
  else
    __file_parser macro typ
      exitm <>
    endm
    __file_parser_class macro typ
      exitm <>
    endm
    __file_parser_library macro typ
      exitm <>
    endm
    __source_code_content macro typ
      exitm <>
    endm
    __class_code_content macro typ
      exitm <>
    endm
    __analysis_assert macro e
      exitm <>
    endm
    __analysis_hint macro hint
      exitm <>
    endm
    __analysis_noreturn equ <>
    __inner_data_source macro src_raw
      exitm <>
    endm
    __inner_this_data_source macro src_raw
      exitm <>
    endm
    __inner_out_validated macro typ_raw
      exitm <>
    endm
    __inner_this_out_validated macro typ_raw
      exitm <>
    endm
    __inner_assume_validated_dec equ <>
    __inner_assume_validated macro p
      exitm <>
    endm
    __inner_transfer macro formal
      exitm <>
    endm
    __inner_encoded equ <>
    __inner_adt_prop macro adt, prop
      exitm <>
    endm
    __inner_adt_add_prop macro adt, prop
      exitm <>
    endm
    __inner_adt_remove_prop macro adt, prop
      exitm <>
    endm
    __inner_adt_transfer_prop macro arg
      exitm <>
    endm
    __inner_adt_type_props macro typ
      exitm <>
    endm
    __inner_volatile equ <>
    __inner_nonvolatile equ <>
    __inner_possibly_notnullterminated equ <>
    _Memory_origin_ macro context
      exitm <>
    endm
    _Memory_origin_when_ macro previousContext, context
      exitm <>
    endm
    _Accessible_bytes_ macro context, expr
      exitm <>
    endm
    _Accessible_bytes_when_ macro previousContext, context, expr
      exitm <>
    endm
    _Pre_accessible_bytes_ macro context, expr
      exitm <>
    endm
    _Pre_accessible_bytes_when_ macro context, previousContext, expr
      exitm <>
    endm
    _User_ equ <>
    _User_on_ macro expr
      exitm <>
    endm
    _User_always_ equ <>
    _User_always_and_needs_probe_on_ macro mode
      exitm <>
    endm
    _Kernel_entry_ equ <>
    _Kernel_entry_always_ equ <>
  endif
  __field_ecount macro size_
    exitm <_SAL1_Source_(__field_ecount, (size_), __notnull __elem_writableTo(size_))>
  endm
  __field_bcount macro size_
    exitm <_SAL1_Source_(__field_bcount, (size_), __notnull __byte_writableTo(size_))>
  endm
  __field_xcount macro size_
    exitm <_SAL1_Source_(__field_xcount, (size_), __notnull __inexpressible_writableTo(size_))>
  endm
  __field_ecount_opt macro size_
    exitm <_SAL1_Source_(__field_ecount_opt, (size_), __maybenull __elem_writableTo(size_))>
  endm
  __field_bcount_opt macro size_
    exitm <_SAL1_Source_(__field_bcount_opt, (size_), __maybenull __byte_writableTo(size_))>
  endm
  __field_xcount_opt macro size_
    exitm <_SAL1_Source_(__field_xcount_opt, (size_), __maybenull __inexpressible_writableTo(size_))>
  endm
  __field_ecount_part macro size_, init
    exitm <_SAL1_Source_(__field_ecount_part, (size_, init), __notnull __elem_writableTo(size_) __elem_readableTo(init))>
  endm
  __field_bcount_part macro size_, init
    exitm <_SAL1_Source_(__field_bcount_part, (size_, init), __notnull __byte_writableTo(size_) __byte_readableTo(init))>
  endm
  __field_xcount_part macro size_, init
    exitm <_SAL1_Source_(__field_xcount_part, (size_, init), __notnull __inexpressible_writableTo(size_) __inexpressible_readableTo(init))>
  endm
  __field_ecount_part_opt macro size_, init
    exitm <_SAL1_Source_(__field_ecount_part_opt, (size_, init), __maybenull __elem_writableTo(size_) __elem_readableTo(init))>
  endm
  __field_bcount_part_opt macro size_, init
    exitm <_SAL1_Source_(__field_bcount_part_opt, (size_, init), __maybenull __byte_writableTo(size_) __byte_readableTo(init))>
  endm
  __field_xcount_part_opt macro size_, init
    exitm <_SAL1_Source_(__field_xcount_part_opt, (size_, init), __maybenull __inexpressible_writableTo(size_) __inexpressible_readableTo(init))>
  endm
  __field_ecount_full macro size_
    exitm <_SAL1_Source_(__field_ecount_full, (size_), __field_ecount_part(size_, size_))>
  endm
  __field_bcount_full macro size_
    exitm <_SAL1_Source_(__field_bcount_full, (size_), __field_bcount_part(size_, size_))>
  endm
  __field_xcount_full macro size_
    exitm <_SAL1_Source_(__field_xcount_full, (size_), __field_xcount_part(size_, size_))>
  endm
  __field_ecount_full_opt macro size_
    exitm <_SAL1_Source_(__field_ecount_full_opt, (size_), __field_ecount_part_opt(size_, size_))>
  endm
  __field_bcount_full_opt macro size_
    exitm <_SAL1_Source_(__field_bcount_full_opt, (size_), __field_bcount_part_opt(size_, size_))>
  endm
  __field_xcount_full_opt macro size_
    exitm <_SAL1_Source_(__field_xcount_full_opt, (size_), __field_xcount_part_opt(size_, size_))>
  endm
  __field_nullterminated equ <_SAL1_Source_(__field_nullterminated,, __nullterminated)>
  __struct_bcount macro size_
    exitm <_SAL1_Source_(__struct_bcount, (size_), __byte_writableTo(size_))>
  endm
  __struct_xcount macro size_
    exitm <_SAL1_Source_(__struct_xcount, (size_), __inexpressible_writableTo(size_))>
  endm
  __out_awcount macro expr, size_
    exitm <_SAL1_Source_(__out_awcount, (expr, size_), _Pre_ __notnull __byte_writableTo((expr) ? (size_) : (size_) * 2) _Post_ __valid __refparam)>
  endm
  __in_awcount macro expr, size_
    exitm <_SAL1_Source_(__in_awcount, (expr, size_), _Pre_ __valid _Pre_ _Notref_ __deref __readonly __byte_readableTo((expr) ? (size_) : (size_) * 2))>
  endm
  __post_invalid equ <_SAL1_Source_(__post_invalid,, _Post_ __notvalid)>
  __allocator equ <_SAL_L_Source_(__allocator,, __inner_allocator)>
  __deallocate macro kind
    exitm <_SAL_L_Source_(__deallocate, (kind), _Pre_ __notnull __post_invalid)>
  endm
  __deallocate_opt macro kind
    exitm <_SAL_L_Source_(__deallocate_opt, (kind), _Pre_ __maybenull __post_invalid)>
  endm
  __bound equ <_SAL_L_Source_(__bound,, __inner_bound)>
  __range macro lb, ub
    exitm <_SAL_L_Source_(__range, (lb, ub), __inner_range(lb, ub))>
  endm
  __in_bound equ <_SAL_L_Source_(__in_bound,, _Pre_ __inner_bound)>
  __out_bound equ <_SAL_L_Source_(__out_bound,, _Post_ __inner_bound)>
  __deref_out_bound equ <_SAL_L_Source_(__deref_out_bound,, _Post_ __deref __inner_bound)>
  __in_range macro lb, ub
    exitm <_SAL_L_Source_(__in_range, (lb, ub), _Pre_ __inner_range(lb, ub))>
  endm
  __out_range macro lb, ub
    exitm <_SAL_L_Source_(__out_range, (lb, ub), _Post_ __inner_range(lb, ub))>
  endm
  __deref_in_range macro lb, ub
    exitm <_SAL_L_Source_(__deref_in_range, (lb, ub), _Pre_ __deref __inner_range(lb, ub))>
  endm
  __deref_out_range macro lb, ub
    exitm <_SAL_L_Source_(__deref_out_range, (lb, ub), _Post_ __deref __inner_range(lb, ub))>
  endm
  __deref_inout_range macro lb, ub
    exitm <_SAL_L_Source_(__deref_inout_range, (lb, ub), __deref_in_range(lb, ub) __deref_out_range(lb, ub))>
  endm
  __field_range macro lb, ub
    exitm <_SAL_L_Source_(__field_range, (lb, ub), __range(lb, ub))>
  endm
  __field_data_source macro src_sym
    exitm <_SAL_L_Source_(__field_data_source, (lb, ub), __inner_data_source(# src_sym))>
  endm
  __range_max macro a, b
    exitm <_SAL_L_Source_(__range_max, (a, b), __range(==, a > b ? a : b))>
  endm
  __range_min macro a, b
    exitm <_SAL_L_Source_(__range_min, (a, b), __range(==, a < b ? a : b))>
  endm
  __in_data_source macro src_sym
    exitm <_SAL_L_Source_(__in_data_source, (src_sym), _Pre_ __inner_data_source(# src_sym))>
  endm
  __out_data_source macro src_sym
    exitm <_SAL_L_Source_(__out_data_source, (src_sym), _Post_ __inner_data_source(# src_sym))>
  endm
  __out_validated macro typ_sym
    exitm <_SAL_L_Source_(__out_validated, (src_sym), __inner_out_validated(# typ_sym))>
  endm
  __this_out_data_source macro src_sym
    exitm <_SAL_L_Source_(__this_out_data_source, (src_sym), __inner_this_data_source(# src_sym))>
  endm
  __this_out_validated macro typ_sym
    exitm <_SAL_L_Source_(__this_out_validated, (src_sym), __inner_this_out_validated(# typ_sym))>
  endm
  __transfer macro formal
    exitm <_SAL_L_Source_(__transfer, (src_sym), _Post_ __inner_transfer(formal))>
  endm
  __rpc_entry equ <_SAL_L_Source_(__rpc_entry, (formal), __inner_control_entrypoint(RPC))>
  __kernel_entry equ <_SAL_L_Source_(__kernel_entry,, __inner_control_entrypoint(UserToKernel))>
  __gdi_entry equ <_SAL_L_Source_(__gdi_entry,, __inner_control_entrypoint(GDI))>
  __encoded_pointer equ <_SAL_L_Source_(__encoded_pointer,, __inner_encoded)>
  __encoded_array equ <_SAL_L_Source_(__encoded_array,, __inner_encoded)>
  __field_encoded_pointer equ <_SAL_L_Source_(__field_encoded_pointer,, __inner_encoded)>
  __field_encoded_array equ <_SAL_L_Source_(__field_encoded_array,, __inner_encoded)>
  if Defined(_MSC_EXTENSIONS) or Defined(_PREFAST_) or Defined(OACR)
    __type_has_adt_prop macro adt, prop
      exitm <_SAL_L_Source_(__type_has_adt_prop, (adt, prop), __inner_adt_prop(adt, prop))>
    endm
    __out_has_adt_prop macro adt, prop
      exitm <_SAL_L_Source_(__out_has_adt_prop, (adt, prop), _Post_ __inner_adt_add_prop(adt, prop))>
    endm
    __out_not_has_adt_prop macro adt, prop
      exitm <_SAL_L_Source_(__out_not_has_adt_prop, (adt, prop), _Post_ __inner_adt_remove_prop(adt, prop))>
    endm
    __out_transfer_adt_prop macro arg
      exitm <_SAL_L_Source_(__out_transfer_adt_prop, (arg), _Post_ __inner_adt_transfer_prop(arg))>
    endm
    __out_has_type_adt_props macro typ
      exitm <_SAL_L_Source_(__out_has_type_adt_props, (typ), _Post_ __inner_adt_type_props(typ))>
    endm
    __possibly_notnullterminated equ <_SAL_L_Source_(__possibly_notnullterminated,, __inner_possibly_notnullterminated)>
    __volatile equ <_SAL_L_Source_(__volatile,, __inner_volatile)>
    __nonvolatile equ <_SAL_L_Source_(__nonvolatile,, __inner_nonvolatile)>
  else
    __out_has_type_adt_props macro typ
      exitm <>
    endm
  endif
  __deref_volatile equ <_SAL_L_Source_(__deref_volatile,, __deref __volatile)>
  __deref_nonvolatile equ <_SAL_L_Source_(__deref_nonvolatile,, __deref __nonvolatile)>
  __analysis_assume_nullterminated macro x
    exitm <_Analysis_assume_nullterminated_(x)>
  endm
  __assume_validated macro p
    exitm <__inner_assume_validated(p)>
  endm
  __assume_bound macro i
    exitm <__inner_assume_bound(i)>
  endm
  ifndef _Unreferenced_parameter_
    _Unreferenced_parameter_ equ <_SAL2_Source_(_Unreferenced_parameter_,, _Const_)>
  endif
  ifndef _Frees_ptr_
    _Frees_ptr_ equ <_SAL_L_Source_(_Frees_ptr_,, _Pre_notnull_ _Post_ptr_invalid_ __drv_freesMem(Mem))>
  endif
  ifndef _Frees_ptr_opt_
    _Frees_ptr_opt_ equ <_SAL_L_Source_(_Frees_ptr_opt_,, _Pre_maybenull_ _Post_ptr_invalid_ __drv_freesMem(Mem))>
  endif
  _Reallocation_function_ macro after, before, size_
    exitm <_Success_((after) != NULL or (size_) == 0) _At_((after), _Post_maybenull_ _Post_writable_byte_size_(size_) _When_(((before) == NULL or (size_) > 0), _Must_inspect_result_)) _At_((before), _Post_ptr_invalid_ __drv_freesMem(Mem))>
  endm
  _Ret_reallocated_bytes_ macro before, size_
    exitm <_Reallocation_function_(_Curr_, before, size_)>
  endm
  _In_NLS_string_ macro size_
    exitm <_SAL_L_Source_(_In_NLS_string_, (size_), _When_((size_) < 0, _In_z_) _When_((size_) >= 0, _In_reads_(size_)))>
  endm
  _Flt_CompletionContext_Outptr_ equ _SAL_L_Source_(_Flt_CompletionContext_Outptr_,, _Outptr_result_maybenull_ _Pre_valid_ _At_(* _Curr_, _Pre_null_ _When_(return != FLT_PREOP_SUCCESS_WITH_CALLBACK and return != FLT_PREOP_SYNCHRONIZE, _Post_null_)))
  _Flt_ConnectionCookie_Outptr_ equ <_SAL_L_Source_(_Flt_ConnectionCookie_Outptr_,, _Outptr_result_maybenull_ _Pre_valid_ _At_(* _Curr_, _Pre_null_ _On_failure_(_Post_null_)))>
  ifndef _Writes_and_advances_ptr_
    _Writes_and_advances_ptr_ macro size_
      exitm <_SAL2_Source_(_Writes_and_advances_ptr_, (size_), _At_(_Curr_, _Inout_) _At_(_Curr_, _Pre_writable_size_(size_) _Post_writable_size_(size_) _Post_satisfies_(_Curr_ - _Old_ (_Curr_) == _Old_ (size_) - size_)) _At_(_Old_ (_Curr_), _Post_readable_size_(_Old_ (size_) - size_)))>
    endm
  endif
  ifndef _Writes_bytes_and_advances_ptr_
    _Writes_bytes_and_advances_ptr_ macro size_
      exitm <_SAL2_Source_(_Writes_bytes_and_advances_ptr, (size_), _At_(_Curr_, _Inout_) _At_(_Curr_, _Pre_writable_byte_size_(size_) _Post_writable_byte_size_(size_) _Post_satisfies_((_Curr_) - (_Old_ (_Curr_)) == _Old_ (size_) - size_)) _At_(_Old_ (_Curr_), _Post_readable_byte_size_(_Old_ (size_) - size_)))>
    endm
  endif
  _Post_equals_last_error_ equ _SAL2_Source_(_Post_equals_last_error_,, _Post_satisfies_(_Curr_ != 0))
  ifndef _Translates_Win32_to_HRESULT_
    _Translates_Win32_to_HRESULT_ macro errorCode
      exitm <_SAL2_Source_(_Translates_Win32_to_HRESULT_, (errorCode), _Always_(_When_(errorCode <= 0, _At_(_Curr_, _Post_equal_to_(errorCode))) _When_(errorCode > 0, _At_(_Curr_, _Post_equal_to_(((errorCode and 0000FFFFh) or (FACILITY_WIN32 shl 16) or 80000000h))))))>
    endm
  endif
  ifndef _Translates_NTSTATUS_to_HRESULT_
    _Translates_NTSTATUS_to_HRESULT_ macro status
      exitm <_SAL2_Source_(_Translates_NTSTATUS_to_HRESULT_, (status), _Always_(_Post_equal_to_((status or FACILITY_NT_BIT))))>
    endm
  endif
  ifndef _Translates_last_error_to_HRESULT_
    _Translates_last_error_to_HRESULT_ equ _SAL2_Source_(_Translates_last_error_to_HRESULT_,, _Always_(_Post_satisfies_(_Curr_ lt 0)))
  endif
  ifdef __cplusplus
    ;[...]
  endif
  ifdef _PREFIX_
    if __cplusplus
      ;[...]
    else
      __pfx_assert proto WIN_STD_CALL_CONV :SDWORD, :ptr SBYTE
      __pfx_assume proto WIN_STD_CALL_CONV :SDWORD, :ptr SBYTE
    endif
    __analysis_assume macro e
      exitm <(__pfx_assume (e, "pfx_assume"), __assume (e)) ;>
    endm
    __analysis_assert macro e
      exitm <(__pfx_assert (e, "pfx_assert"), __assume (e)) ;>
    endm
  endif
  if  not (Defined(RC_INVOKED) or Defined(SORTPP_PASS))
    include specstrings_strict.inc
  endif
  if ( not Defined(_Outptr_) or _MSC_FULL_VER le 160000000) and  not (Defined(MIDL_PASS) or Defined(__midl) or Defined(RC_INVOKED))
    __ANNOTATION macro fun
      exitm <>
    endm
    __PRIMOP macro type_, fun
      exitm <>
    endm
  endif
  include driverspecs.inc
  if ( not Defined(_Outptr_) or _MSC_FULL_VER le 160000000) and  not (Defined(MIDL_PASS) or Defined(__midl) or Defined(RC_INVOKED)) and  not (Defined(_SDV_))
    include no_sal2.inc
  endif
  if _MSC_VER ge 1200
  endif
endif
