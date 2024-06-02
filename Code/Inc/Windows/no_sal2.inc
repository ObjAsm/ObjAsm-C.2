;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\no_sal2.h
;             Created on (UTC) 22/05/2024 17:57:07
;             Last modified on (UTC) 21/02/2024 18:14:46

ifndef _NO_SAL_2_H_
  _NO_SAL_2_H_ equ <>
  ifdef _When_
  endif
  _When_ macro c_, a
    exitm <>
  endm
  ifdef _At_
  endif
  _At_ macro t, a
    exitm <>
  endm
  ifdef _At_buffer_
  endif
  _At_buffer_ macro t, i, c_, a
    exitm <>
  endm
  ifdef _Group_
  endif
  _Group_ macro a
    exitm <>
  endm
  ifdef _Pre_
  endif
  _Pre_ equ <>
  ifdef _Post_
  endif
  _Post_ equ <>
  ifdef _Deref_
  endif
  _Deref_ equ <>
  ifdef _Null_
  endif
  _Null_ equ <>
  ifdef _Notnull_
  endif
  _Notnull_ equ <>
  ifdef _Maybenull_
  endif
  _Maybenull_ equ <>
  ifdef _Const_
  endif
  _Const_ equ <>
  ifdef _Check_return_
  endif
  _Check_return_ equ <>
  ifdef _Must_inspect_result_
  endif
  _Must_inspect_result_ equ <>
  ifdef _Pre_satisfies_
  endif
  _Pre_satisfies_ macro e
    exitm <>
  endm
  ifdef _Post_satisfies_
  endif
  _Post_satisfies_ macro e
    exitm <>
  endm
  ifdef _Writable_elements_
  endif
  _Writable_elements_ macro s
    exitm <>
  endm
  ifdef _Writable_bytes_
  endif
  _Writable_bytes_ macro s
    exitm <>
  endm
  ifdef _Readable_elements_
  endif
  _Readable_elements_ macro s
    exitm <>
  endm
  ifdef _Readable_bytes_
  endif
  _Readable_bytes_ macro s
    exitm <>
  endm
  ifdef _Null_terminated_
  endif
  _Null_terminated_ equ <>
  ifdef _NullNull_terminated_
  endif
  _NullNull_terminated_ equ <>
  ifdef _Valid_
  endif
  _Valid_ equ <>
  ifdef _Notvalid_
  endif
  _Notvalid_ equ <>
  ifdef _Success_
  endif
  _Success_ macro c_
    exitm <>
  endm
  ifdef _Return_type_success_
  endif
  _Return_type_success_ macro c_
    exitm <>
  endm
  ifdef _On_failure_
  endif
  _On_failure_ macro a
    exitm <>
  endm
  ifdef _Always_
  endif
  _Always_ macro a
    exitm <>
  endm
  ifdef _Use_decl_annotations_
  endif
  _Use_decl_annotations_ equ <>
  ifdef _Pre_defensive_
  endif
  _Pre_defensive_ equ <>
  ifdef _Post_defensive_
  endif
  _Post_defensive_ equ <>
  ifdef _Pre_unknown_
  endif
  _Pre_unknown_ equ <>
  ifdef _Acquires_lock_
  endif
  _Acquires_lock_ macro e
    exitm <>
  endm
  ifdef _Releases_lock_
  endif
  _Releases_lock_ macro e
    exitm <>
  endm
  ifdef _Requires_lock_held_
  endif
  _Requires_lock_held_ macro e
    exitm <>
  endm
  ifdef _Requires_lock_not_held_
  endif
  _Requires_lock_not_held_ macro e
    exitm <>
  endm
  ifdef _Requires_no_locks_held_
  endif
  _Requires_no_locks_held_ equ <>
  ifdef _Guarded_by_
  endif
  _Guarded_by_ macro e
    exitm <>
  endm
  ifdef _Write_guarded_by_
  endif
  _Write_guarded_by_ macro e
    exitm <>
  endm
  ifdef _Interlocked_
  endif
  _Interlocked_ equ <>
  ifdef _Post_same_lock_
  endif
  _Post_same_lock_ macro e1, e2
    exitm <>
  endm
  ifdef _Benign_race_begin_
  endif
  _Benign_race_begin_ equ <>
  ifdef _Benign_race_end_
  endif
  _Benign_race_end_ equ <>
  ifdef _No_competing_thread_
  endif
  _No_competing_thread_ equ <>
  ifdef _No_competing_thread_begin_
  endif
  _No_competing_thread_begin_ equ <>
  ifdef _No_competing_thread_end_
  endif
  _No_competing_thread_end_ equ <>
  ifdef _Acquires_shared_lock_
  endif
  _Acquires_shared_lock_ macro e
    exitm <>
  endm
  ifdef _Releases_shared_lock_
  endif
  _Releases_shared_lock_ macro e
    exitm <>
  endm
  ifdef _Requires_shared_lock_held_
  endif
  _Requires_shared_lock_held_ macro e
    exitm <>
  endm
  ifdef _Acquires_exclusive_lock_
  endif
  _Acquires_exclusive_lock_ macro e
    exitm <>
  endm
  ifdef _Releases_exclusive_lock_
  endif
  _Releases_exclusive_lock_ macro e
    exitm <>
  endm
  ifdef _Requires_exclusive_lock_held_
  endif
  _Requires_exclusive_lock_held_ macro e
    exitm <>
  endm
  ifdef _Has_lock_kind_
  endif
  _Has_lock_kind_ macro n
    exitm <>
  endm
  ifdef _Create_lock_level_
  endif
  _Create_lock_level_ macro n
    exitm <>
  endm
  ifdef _Has_lock_level_
  endif
  _Has_lock_level_ macro n
    exitm <>
  endm
  ifdef _Lock_level_order_
  endif
  _Lock_level_order_ macro n1, n2
    exitm <>
  endm
  ifdef _Analysis_assume_lock_acquired_
  endif
  _Analysis_assume_lock_acquired_ macro e
    exitm <>
  endm
  ifdef _Analysis_assume_lock_released_
  endif
  _Analysis_assume_lock_released_ macro e
    exitm <>
  endm
  ifdef _Analysis_assume_lock_held_
  endif
  _Analysis_assume_lock_held_ macro e
    exitm <>
  endm
  ifdef _Analysis_assume_lock_not_held_
  endif
  _Analysis_assume_lock_not_held_ macro e
    exitm <>
  endm
  ifdef _Analysis_assume_same_lock_
  endif
  _Analysis_assume_same_lock_ macro e
    exitm <>
  endm
  ifdef _In_
  endif
  _In_ equ <>
  ifdef _Out_
  endif
  _Out_ equ <>
  ifdef _Inout_
  endif
  _Inout_ equ <>
  ifdef _In_z_
  endif
  _In_z_ equ <>
  ifdef _Inout_z_
  endif
  _Inout_z_ equ <>
  ifdef _In_reads_
  endif
  _In_reads_ macro s
    exitm <>
  endm
  ifdef _In_reads_bytes_
  endif
  _In_reads_bytes_ macro s
    exitm <>
  endm
  ifdef _In_reads_z_
  endif
  _In_reads_z_ macro s
    exitm <>
  endm
  ifdef _In_reads_or_z_
  endif
  _In_reads_or_z_ macro s
    exitm <>
  endm
  ifdef _Out_writes_
  endif
  _Out_writes_ macro s
    exitm <>
  endm
  ifdef _Out_writes_bytes_
  endif
  _Out_writes_bytes_ macro s
    exitm <>
  endm
  ifdef _Out_writes_z_
  endif
  _Out_writes_z_ macro s
    exitm <>
  endm
  ifdef _Inout_updates_
  endif
  _Inout_updates_ macro s
    exitm <>
  endm
  ifdef _Inout_updates_bytes_
  endif
  _Inout_updates_bytes_ macro s
    exitm <>
  endm
  ifdef _Inout_updates_z_
  endif
  _Inout_updates_z_ macro s
    exitm <>
  endm
  ifdef _Out_writes_to_
  endif
  _Out_writes_to_ macro s, c_
    exitm <>
  endm
  ifdef _Out_writes_bytes_to_
  endif
  _Out_writes_bytes_to_ macro s, c_
    exitm <>
  endm
  ifdef _Out_writes_all_
  endif
  _Out_writes_all_ macro s
    exitm <>
  endm
  ifdef _Out_writes_bytes_all_
  endif
  _Out_writes_bytes_all_ macro s
    exitm <>
  endm
  ifdef _Inout_updates_to_
  endif
  _Inout_updates_to_ macro s, c_
    exitm <>
  endm
  ifdef _Inout_updates_bytes_to_
  endif
  _Inout_updates_bytes_to_ macro s, c_
    exitm <>
  endm
  ifdef _Inout_updates_all_
  endif
  _Inout_updates_all_ macro s
    exitm <>
  endm
  ifdef _Inout_updates_bytes_all_
  endif
  _Inout_updates_bytes_all_ macro s
    exitm <>
  endm
  ifdef _In_reads_to_ptr_
  endif
  _In_reads_to_ptr_ macro p
    exitm <>
  endm
  ifdef _In_reads_to_ptr_z_
  endif
  _In_reads_to_ptr_z_ macro p
    exitm <>
  endm
  ifdef _Out_writes_to_ptr_
  endif
  _Out_writes_to_ptr_ macro p
    exitm <>
  endm
  ifdef _Out_writes_to_ptr_z_
  endif
  _Out_writes_to_ptr_z_ macro p
    exitm <>
  endm
  ifdef _In_opt_
  endif
  _In_opt_ equ <>
  ifdef _Out_opt_
  endif
  _Out_opt_ equ <>
  ifdef _Inout_opt_
  endif
  _Inout_opt_ equ <>
  ifdef _In_opt_z_
  endif
  _In_opt_z_ equ <>
  ifdef _Inout_opt_z_
  endif
  _Inout_opt_z_ equ <>
  ifdef _In_reads_opt_
  endif
  _In_reads_opt_ macro s
    exitm <>
  endm
  ifdef _In_reads_opt_z_
  endif
  _In_reads_opt_z_ macro s
    exitm <>
  endm
  ifdef _In_reads_bytes_opt_
  endif
  _In_reads_bytes_opt_ macro s
    exitm <>
  endm
  ifdef _Out_writes_opt_
  endif
  _Out_writes_opt_ macro s
    exitm <>
  endm
  ifdef _Out_writes_bytes_opt_
  endif
  _Out_writes_bytes_opt_ macro s
    exitm <>
  endm
  ifdef _Out_writes_opt_z_
  endif
  _Out_writes_opt_z_ macro s
    exitm <>
  endm
  ifdef _Inout_updates_opt_
  endif
  _Inout_updates_opt_ macro s
    exitm <>
  endm
  ifdef _Inout_updates_bytes_opt_
  endif
  _Inout_updates_bytes_opt_ macro s
    exitm <>
  endm
  ifdef _Inout_updates_opt_z_
  endif
  _Inout_updates_opt_z_ macro s
    exitm <>
  endm
  ifdef _Out_writes_to_opt_
  endif
  _Out_writes_to_opt_ macro s, c_
    exitm <>
  endm
  ifdef _Out_writes_bytes_to_opt_
  endif
  _Out_writes_bytes_to_opt_ macro s, c_
    exitm <>
  endm
  ifdef _Out_writes_all_opt_
  endif
  _Out_writes_all_opt_ macro s
    exitm <>
  endm
  ifdef _Out_writes_bytes_all_opt_
  endif
  _Out_writes_bytes_all_opt_ macro s
    exitm <>
  endm
  ifdef _Inout_updates_to_opt_
  endif
  _Inout_updates_to_opt_ macro s, c_
    exitm <>
  endm
  ifdef _Inout_updates_bytes_to_opt_
  endif
  _Inout_updates_bytes_to_opt_ macro s, c_
    exitm <>
  endm
  ifdef _Inout_updates_all_opt_
  endif
  _Inout_updates_all_opt_ macro s
    exitm <>
  endm
  ifdef _Inout_updates_bytes_all_opt_
  endif
  _Inout_updates_bytes_all_opt_ macro s
    exitm <>
  endm
  ifdef _In_reads_to_ptr_opt_
  endif
  _In_reads_to_ptr_opt_ macro p
    exitm <>
  endm
  ifdef _In_reads_to_ptr_opt_z_
  endif
  _In_reads_to_ptr_opt_z_ macro p
    exitm <>
  endm
  ifdef _Out_writes_to_ptr_opt_
  endif
  _Out_writes_to_ptr_opt_ macro p
    exitm <>
  endm
  ifdef _Out_writes_to_ptr_opt_z_
  endif
  _Out_writes_to_ptr_opt_z_ macro p
    exitm <>
  endm
  ifdef _Outptr_
  endif
  _Outptr_ equ <>
  ifdef _Outptr_opt_
  endif
  _Outptr_opt_ equ <>
  ifdef _Outptr_result_maybenull_
  endif
  _Outptr_result_maybenull_ equ <>
  ifdef _Outptr_opt_result_maybenull_
  endif
  _Outptr_opt_result_maybenull_ equ <>
  ifdef _Outptr_result_z_
  endif
  _Outptr_result_z_ equ <>
  ifdef _Outptr_opt_result_z_
  endif
  _Outptr_opt_result_z_ equ <>
  ifdef _Outptr_result_maybenull_z_
  endif
  _Outptr_result_maybenull_z_ equ <>
  ifdef _Outptr_opt_result_maybenull_z_
  endif
  _Outptr_opt_result_maybenull_z_ equ <>
  ifdef _COM_Outptr_
  endif
  _COM_Outptr_ equ <>
  ifdef _COM_Outptr_opt_
  endif
  _COM_Outptr_opt_ equ <>
  ifdef _COM_Outptr_result_maybenull_
  endif
  _COM_Outptr_result_maybenull_ equ <>
  ifdef _COM_Outptr_opt_result_maybenull_
  endif
  _COM_Outptr_opt_result_maybenull_ equ <>
  ifdef _Outptr_result_buffer_
  endif
  _Outptr_result_buffer_ macro s
    exitm <>
  endm
  ifdef _Outptr_result_buffer_maybenull_
  endif
  _Outptr_result_buffer_maybenull_ macro s
    exitm <>
  endm
  ifdef _Outptr_result_bytebuffer_
  endif
  _Outptr_result_bytebuffer_ macro s
    exitm <>
  endm
  ifdef _Outptr_result_bytebuffer_maybenull_
  endif
  _Outptr_result_bytebuffer_maybenull_ macro s
    exitm <>
  endm
  ifdef _Outptr_opt_result_buffer_
  endif
  _Outptr_opt_result_buffer_ macro s
    exitm <>
  endm
  ifdef _Outptr_opt_result_buffer_maybenull_
  endif
  _Outptr_opt_result_buffer_maybenull_ macro s
    exitm <>
  endm
  ifdef _Outptr_opt_result_bytebuffer_
  endif
  _Outptr_opt_result_bytebuffer_ macro s
    exitm <>
  endm
  ifdef _Outptr_opt_result_bytebuffer_maybenull_
  endif
  _Outptr_opt_result_bytebuffer_maybenull_ macro s
    exitm <>
  endm
  ifdef _Outptr_result_buffer_to_
  endif
  _Outptr_result_buffer_to_ macro s, c_
    exitm <>
  endm
  ifdef _Outptr_result_bytebuffer_to_
  endif
  _Outptr_result_bytebuffer_to_ macro s, c_
    exitm <>
  endm
  ifdef _Outptr_opt_result_buffer_to_
  endif
  _Outptr_opt_result_buffer_to_ macro s, c_
    exitm <>
  endm
  ifdef _Outptr_opt_result_bytebuffer_to_
  endif
  _Outptr_opt_result_bytebuffer_to_ macro s, c_
    exitm <>
  endm
  ifdef _Ret_
  endif
  _Ret_ equ <>
  ifdef _Ret_valid_
  endif
  _Ret_valid_ equ <>
  ifdef _Ret_z_
  endif
  _Ret_z_ equ <>
  ifdef _Ret_writes_
  endif
  _Ret_writes_ macro s
    exitm <>
  endm
  ifdef _Ret_writes_bytes_
  endif
  _Ret_writes_bytes_ macro s
    exitm <>
  endm
  ifdef _Ret_writes_z_
  endif
  _Ret_writes_z_ macro s
    exitm <>
  endm
  ifdef _Ret_writes_to_
  endif
  _Ret_writes_to_ macro s, c_
    exitm <>
  endm
  ifdef _Ret_writes_bytes_to_
  endif
  _Ret_writes_bytes_to_ macro s, c_
    exitm <>
  endm
  ifdef _Ret_writes_to_ptr_
  endif
  _Ret_writes_to_ptr_ macro p
    exitm <>
  endm
  ifdef _Ret_writes_to_ptr_z_
  endif
  _Ret_writes_to_ptr_z_ macro p
    exitm <>
  endm
  ifdef _Ret_writes_maybenull_
  endif
  _Ret_writes_maybenull_ macro s
    exitm <>
  endm
  ifdef _Ret_writes_bytes_maybenull_
  endif
  _Ret_writes_bytes_maybenull_ macro s
    exitm <>
  endm
  ifdef _Ret_writes_to_maybenull_
  endif
  _Ret_writes_to_maybenull_ macro s, c_
    exitm <>
  endm
  ifdef _Ret_writes_bytes_to_maybenull_
  endif
  _Ret_writes_bytes_to_maybenull_ macro s, c_
    exitm <>
  endm
  ifdef _Ret_writes_maybenull_z_
  endif
  _Ret_writes_maybenull_z_ macro s
    exitm <>
  endm
  ifdef _Ret_null_
  endif
  _Ret_null_ equ <>
  ifdef _Ret_notnull_
  endif
  _Ret_notnull_ equ <>
  ifdef _Ret_maybenull_
  endif
  _Ret_maybenull_ equ <>
  ifdef _Ret_maybenull_z_
  endif
  _Ret_maybenull_z_ equ <>
  ifdef _Field_size_
  endif
  _Field_size_ macro s
    exitm <>
  endm
  ifdef _Field_size_opt_
  endif
  _Field_size_opt_ macro s
    exitm <>
  endm
  ifdef _Field_size_bytes_
  endif
  _Field_size_bytes_ macro s
    exitm <>
  endm
  ifdef _Field_size_bytes_opt_
  endif
  _Field_size_bytes_opt_ macro s
    exitm <>
  endm
  ifdef _Field_size_part_
  endif
  _Field_size_part_ macro s, c_
    exitm <>
  endm
  ifdef _Field_size_part_opt_
  endif
  _Field_size_part_opt_ macro s, c_
    exitm <>
  endm
  ifdef _Field_size_bytes_part_
  endif
  _Field_size_bytes_part_ macro s, c_
    exitm <>
  endm
  ifdef _Field_size_bytes_part_opt_
  endif
  _Field_size_bytes_part_opt_ macro s, c_
    exitm <>
  endm
  ifdef _Field_size_full_
  endif
  _Field_size_full_ macro s
    exitm <>
  endm
  ifdef _Field_size_full_opt_
  endif
  _Field_size_full_opt_ macro s
    exitm <>
  endm
  ifdef _Field_size_bytes_full_
  endif
  _Field_size_bytes_full_ macro s
    exitm <>
  endm
  ifdef _Field_size_bytes_full_opt_
  endif
  _Field_size_bytes_full_opt_ macro s
    exitm <>
  endm
  ifdef _Printf_format_string_
  endif
  _Printf_format_string_ equ <>
  ifdef _Scanf_format_string_
  endif
  _Scanf_format_string_ equ <>
  ifdef _Scanf_s_format_string_
  endif
  _Scanf_s_format_string_ equ <>
  ifdef _Printf_format_string_params_
  endif
  _Printf_format_string_params_ macro x
    exitm <>
  endm
  ifdef _Scanf_format_string_params_
  endif
  _Scanf_format_string_params_ macro x
    exitm <>
  endm
  ifdef _Scanf_s_format_string_params_
  endif
  _Scanf_s_format_string_params_ macro x
    exitm <>
  endm
  ifdef _In_range_
  endif
  _In_range_ macro l, h
    exitm <>
  endm
  ifdef _Out_range_
  endif
  _Out_range_ macro l, h
    exitm <>
  endm
  ifdef _Ret_range_
  endif
  _Ret_range_ macro l, h
    exitm <>
  endm
  ifdef _Deref_in_range_
  endif
  _Deref_in_range_ macro l, h
    exitm <>
  endm
  ifdef _Deref_out_range_
  endif
  _Deref_out_range_ macro l, h
    exitm <>
  endm
  ifdef _Deref_inout_range_
  endif
  _Deref_inout_range_ macro l, h
    exitm <>
  endm
  ifdef _Field_range_
  endif
  _Field_range_ macro l, h
    exitm <>
  endm
  ifdef _Pre_equal_to_
  endif
  _Pre_equal_to_ macro e
    exitm <>
  endm
  ifdef _Post_equal_to_
  endif
  _Post_equal_to_ macro e
    exitm <>
  endm
  ifdef _Struct_size_bytes_
  endif
  _Struct_size_bytes_ macro s
    exitm <>
  endm
  ifdef _Analysis_assume_
  endif
  _Analysis_assume_ equ <>
  ifdef _Analysis_assume_nullterminated_
  endif
  _Analysis_assume_nullterminated_ macro s
    exitm <>
  endm
  ifdef _Analysis_mode_
  endif
  _Analysis_mode_ macro m
    exitm <>
  endm
  ifdef _Analysis_noreturn_
  endif
  _Analysis_noreturn_ equ <>
  ifdef _Raises_SEH_exception_
  endif
  _Raises_SEH_exception_ equ <>
  ifdef _Maybe_raises_SEH_exception_
  endif
  _Maybe_raises_SEH_exception_ equ <>
  ifdef _Function_class_
  endif
  _Function_class_ macro n
    exitm <>
  endm
  ifdef _Literal_
  endif
  _Literal_ equ <>
  ifdef _Notliteral_
  endif
  _Notliteral_ equ <>
  ifdef _Enum_is_bitflag_
  endif
  _Enum_is_bitflag_ equ <>
  ifdef _Strict_type_match_
  endif
  _Strict_type_match_ equ <>
  ifdef _Points_to_data_
  endif
  _Points_to_data_ equ <>
  ifdef _Interlocked_operand_
  endif
  _Interlocked_operand_ equ <>
  ifdef _IRQL_raises_
  endif
  _IRQL_raises_ macro i
    exitm <>
  endm
  ifdef _IRQL_requires_
  endif
  _IRQL_requires_ macro i
    exitm <>
  endm
  ifdef _IRQL_requires_max_
  endif
  _IRQL_requires_max_ macro i
    exitm <>
  endm
  ifdef _IRQL_requires_min_
  endif
  _IRQL_requires_min_ macro i
    exitm <>
  endm
  ifdef _IRQL_saves_
  endif
  _IRQL_saves_ equ <>
  ifdef _IRQL_saves_global_
  endif
  _IRQL_saves_global_ macro k, s
    exitm <>
  endm
  ifdef _IRQL_restores_
  endif
  _IRQL_restores_ equ <>
  ifdef _IRQL_restores_global_
  endif
  _IRQL_restores_global_ macro k, s
    exitm <>
  endm
  ifdef _IRQL_always_function_min_
  endif
  _IRQL_always_function_min_ macro i
    exitm <>
  endm
  ifdef _IRQL_always_function_max_
  endif
  _IRQL_always_function_max_ macro i
    exitm <>
  endm
  ifdef _IRQL_requires_same_
  endif
  _IRQL_requires_same_ equ <>
  ifdef _IRQL_uses_cancel_
  endif
  _IRQL_uses_cancel_ equ <>
  ifdef _IRQL_is_cancel_
  endif
  _IRQL_is_cancel_ equ <>
  ifdef _Kernel_float_saved_
  endif
  _Kernel_float_saved_ equ <>
  ifdef _Kernel_float_restored_
  endif
  _Kernel_float_restored_ equ <>
  ifdef _Kernel_float_used_
  endif
  _Kernel_float_used_ equ <>
  ifdef _Kernel_acquires_resource_
  endif
  _Kernel_acquires_resource_ macro k
    exitm <>
  endm
  ifdef _Kernel_releases_resource_
  endif
  _Kernel_releases_resource_ macro k
    exitm <>
  endm
  ifdef _Kernel_requires_resource_held_
  endif
  _Kernel_requires_resource_held_ macro k
    exitm <>
  endm
  ifdef _Kernel_requires_resource_not_held_
  endif
  _Kernel_requires_resource_not_held_ macro k
    exitm <>
  endm
  ifdef _Kernel_clear_do_init_
  endif
  _Kernel_clear_do_init_ macro yn
    exitm <>
  endm
  ifdef _Kernel_IoGetDmaAdapter_
  endif
  _Kernel_IoGetDmaAdapter_ equ <>
  ifdef _Outref_
  endif
  _Outref_ equ <>
  ifdef _Outref_result_maybenull_
  endif
  _Outref_result_maybenull_ equ <>
  ifdef _Outref_result_buffer_
  endif
  _Outref_result_buffer_ macro s
    exitm <>
  endm
  ifdef _Outref_result_bytebuffer_
  endif
  _Outref_result_bytebuffer_ macro s
    exitm <>
  endm
  ifdef _Outref_result_buffer_to_
  endif
  _Outref_result_buffer_to_ macro s, c_
    exitm <>
  endm
  ifdef _Outref_result_bytebuffer_to_
  endif
  _Outref_result_bytebuffer_to_ macro s, c_
    exitm <>
  endm
  ifdef _Outref_result_buffer_all_
  endif
  _Outref_result_buffer_all_ macro s
    exitm <>
  endm
  ifdef _Outref_result_bytebuffer_all_
  endif
  _Outref_result_bytebuffer_all_ macro s
    exitm <>
  endm
  ifdef _Outref_result_buffer_maybenull_
  endif
  _Outref_result_buffer_maybenull_ macro s
    exitm <>
  endm
  ifdef _Outref_result_bytebuffer_maybenull_
  endif
  _Outref_result_bytebuffer_maybenull_ macro s
    exitm <>
  endm
  ifdef _Outref_result_buffer_to_maybenull_
  endif
  _Outref_result_buffer_to_maybenull_ macro s, c_
    exitm <>
  endm
  ifdef _Outref_result_bytebuffer_to_maybenull_
  endif
  _Outref_result_bytebuffer_to_maybenull_ macro s, c_
    exitm <>
  endm
  ifdef _Outref_result_buffer_all_maybenull_
  endif
  _Outref_result_buffer_all_maybenull_ macro s
    exitm <>
  endm
  ifdef _Outref_result_bytebuffer_all_maybenull_
  endif
  _Outref_result_bytebuffer_all_maybenull_ macro s
    exitm <>
  endm
  ifdef _In_defensive_
  endif
  _In_defensive_ macro a
    exitm <>
  endm
  ifdef _Out_defensive_
  endif
  _Out_defensive_ macro a
    exitm <>
  endm
  ifdef _Inout_defensive_
  endif
  _Inout_defensive_ macro a
    exitm <>
  endm
  ifdef _Outptr_result_nullonfailure_
  endif
  _Outptr_result_nullonfailure_ equ <>
  ifdef _Outptr_opt_result_nullonfailure_
  endif
  _Outptr_opt_result_nullonfailure_ equ <>
  ifdef _Outref_result_nullonfailure_
  endif
  _Outref_result_nullonfailure_ equ <>
  ifdef _Result_nullonfailure_
  endif
  _Result_nullonfailure_ equ <>
  ifdef _Result_zeroonfailure_
  endif
  _Result_zeroonfailure_ equ <>
  ifdef _Acquires_nonreentrant_lock_
  endif
  _Acquires_nonreentrant_lock_ macro e
    exitm <>
  endm
  ifdef _Releases_nonreentrant_lock_
  endif
  _Releases_nonreentrant_lock_ macro e
    exitm <>
  endm
  ifdef _Function_ignore_lock_checking_
  endif
  _Function_ignore_lock_checking_ macro e
    exitm <>
  endm
  ifdef _Analysis_suppress_lock_checking_
  endif
  _Analysis_suppress_lock_checking_ macro e
    exitm <>
  endm
  _Reserved_ equ _Pre_equal_to_(0) _Pre_ _Null_
  _Pre_z_ equ <_Pre_ _Null_terminated_>
  _Post_z_ equ <_Post_ _Null_terminated_>
  _Prepost_z_ equ <_Pre_z_ _Post_z_>
  _Pre_null_ equ <_Pre_ _Null_>
  _Pre_maybenull_ equ <_Pre_ _Maybenull_>
  _Pre_notnull_ equ <_Pre_ _Notnull_>
  _Pre_valid_ equ <_Pre_notnull_ _Pre_ _Valid_>
  _Pre_opt_valid_ equ <_Pre_maybenull_ _Pre_ _Valid_>
  _Post_valid_ equ <_Post_ _Valid_>
  _Post_invalid_ equ <_Post_ _Deref_ _Notvalid_>
  _Post_ptr_invalid_ equ <_Post_ _Notvalid_>
  _Pre_readable_size_ macro s
    exitm <_Pre_ _Readable_elements_(s) _Pre_ _Valid_>
  endm
  _Pre_writable_size_ macro s
    exitm <_Pre_ _Writable_elements_(s)>
  endm
  _Pre_readable_byte_size_ macro s
    exitm <_Pre_ _Readable_bytes_(s) _Pre_ _Valid_>
  endm
  _Pre_writable_byte_size_ macro s
    exitm <_Pre_ _Writable_bytes_(s)>
  endm
  _Post_readable_size_ macro s
    exitm <_Post_ _Readable_elements_(s) _Post_ _Valid_>
  endm
  _Post_writable_size_ macro s
    exitm <_Post_ _Writable_elements_(s)>
  endm
  _Post_readable_byte_size_ macro s
    exitm <_Post_ _Readable_bytes_(s) _Post_ _Valid_>
  endm
  _Post_writable_byte_size_ macro s
    exitm <_Post_ _Writable_bytes_(s)>
  endm
endif
