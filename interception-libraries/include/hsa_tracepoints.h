#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER interceptionTracer

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./hsa_tracepoints.h"

#if !defined(HSA_TRACEPOINTS_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define HSA_TRACEPOINTS_H

#include <lttng/tracepoint.h>
#include <GPUPerfAPI-HSA.h>

TRACEPOINT_EVENT(
	interceptionTracer,
	runtime_initialized,
	TP_ARGS(
		const char*, cat_arg
	),
	TP_FIELDS(
		ctf_string(cat, cat_arg)
	)
)

TRACEPOINT_EVENT(
	interceptionTracer,
	runtime_shut_down,
	TP_ARGS(
		const char*, cat_arg
	),
	TP_FIELDS(
		ctf_string(cat, cat_arg)
	)
)

/* call_stack */

TRACEPOINT_EVENT(
	interceptionTracer,
	function_entry,
	TP_ARGS(
		const char*, cat_arg,
		char*, name
	),
	TP_FIELDS(
		ctf_string(cat, cat_arg)
		ctf_string(name, name)
	)
)

TRACEPOINT_EVENT(
	interceptionTracer,
	function_exit,
	TP_ARGS(
		const char*, cat_arg,
		char*, name
	),
	TP_FIELDS(
		ctf_string(cat, cat_arg)
		ctf_string(name, name)
	)
)

/* queue_profiling */

TRACEPOINT_EVENT(
	interceptionTracer,
	queue_created,
	TP_ARGS(
		const char*, cat_arg,
		uint64_t, agent_handle,
		uint64_t, queue_id
	),
	TP_FIELDS(
		ctf_string(cat, cat_arg)
		ctf_integer_hex(uint64_t, agent_handle, agent_handle)
		ctf_integer(uint64_t, queue_id, queue_id)
	)
)

TRACEPOINT_EVENT(
	interceptionTracer,
	queue_destroyed,
	TP_ARGS(
		const char*, cat_arg,
		uint64_t, queue_id
	),
	TP_FIELDS(
		ctf_string(cat, cat_arg)
		ctf_integer(uint64_t, queue_id, queue_id)
	)
)

TRACEPOINT_EVENT(
	interceptionTracer,
	aql_packet_submitted,
	TP_ARGS(
		const char*, cat_arg,
		uint64_t, packet_id,
		const char*, packet_type,
		uint64_t, agent_handle,
		uint64_t, queue_id
	),
	TP_FIELDS(
		ctf_string(cat, cat_arg)
		ctf_integer(uint64_t, packet_id, packet_id)
		ctf_string(packet_type, packet_type)
		ctf_integer_hex(uint64_t, agent_handle, agent_handle)
		ctf_integer(uint64_t, queue_id, queue_id)
	)
)

TRACEPOINT_EVENT(
	interceptionTracer,
	aql_kernel_dispatch_packet_submitted,
	TP_ARGS(
		const char*, cat_arg,
		uint64_t, packet_id,
		uint64_t, agent_handle,
		uint64_t, queue_id,
		uint64_t, kernel_object,
		const char*, kernel_name
	),
	TP_FIELDS(
		ctf_string(cat, cat_arg)
		ctf_integer(uint64_t, packet_id, packet_id)
		ctf_integer_hex(uint64_t, agent_handle, agent_handle)
		ctf_integer(uint64_t, queue_id, queue_id)
		ctf_integer_hex(uint64_t, kernel_object, kernel_object)
		ctf_string(kernel_name, kernel_name)
	)
)

/* kernel_times */

TRACEPOINT_EVENT(
	interceptionTracer,
	kernel_begin,
	TP_ARGS(
		const char*, cat_arg,
		uint64_t, kernel_object,
		const char*, name,
		const char*, tf_name,
		uint64_t, agent_handle,
		uint64_t, queue_id,
		uint64_t, timestamp
	),
	TP_FIELDS(
		ctf_string(cat, cat_arg)
		ctf_integer_hex(uint64_t, kernel_object, kernel_object)
		ctf_string(name, name)
		ctf_string(tf_name, tf_name)
		ctf_integer_hex(uint64_t, agent_handle, agent_handle)
		ctf_integer(uint64_t, queue_id, queue_id)
		ctf_integer(uint64_t, timestamp, timestamp)
	)
)

TRACEPOINT_EVENT(
	interceptionTracer,
	kernel_end,
	TP_ARGS(
		const char*, cat_arg,
		uint64_t, kernel_object,
		const char*, name,
		const char*, tf_name,
		uint64_t, agent_handle,
		uint64_t, queue_id,
		uint64_t, timestamp
	),
	TP_FIELDS(
		ctf_string(cat, cat_arg)
		ctf_integer_hex(uint64_t, kernel_object, kernel_object)
		ctf_string(name, name)
		ctf_string(tf_name, tf_name)
		ctf_integer_hex(uint64_t, agent_handle, agent_handle)
		ctf_integer(uint64_t, queue_id, queue_id)
		ctf_integer(uint64_t, timestamp, timestamp)
	)
)

/* perf_counters */

TRACEPOINT_EVENT(
	interceptionTracer,
	kernel_parameters,
	TP_ARGS(
		uint16_t*, workgroup_size_arg,
        uint32_t*, grid_size_arg,
        uint64_t, static_group_segment_size_arg,
		uint64_t, private_segment_size_arg

	),
	TP_FIELDS(
		ctf_array(uint16_t, workgroup_size, workgroup_size_arg, 3)
		ctf_array(uint32_t, grid_size, grid_size_arg, 3)
		ctf_integer(uint64_t, static_group_segment_size, static_group_segment_size_arg)
		ctf_integer(uint64_t, private_segment_size, private_segment_size_arg)
	)
)

TRACEPOINT_EVENT(
	interceptionTracer,
	perf_counter_uint32,
	TP_ARGS(
		const char*, cat_arg,
		uint64_t, kernel_object,
		gpa_uint32, counter_index,
		const char*, counter_name,
		uint32_t, value
	),
	TP_FIELDS(
		ctf_string(cat, cat_arg)
		ctf_integer_hex(uint64_t, kernel_object, kernel_object)
		ctf_integer(uint32_t, counter_index, counter_index)
		ctf_string(counter_name, counter_name)
		ctf_integer(uint32_t, value, value)
	)
)

TRACEPOINT_EVENT(
	interceptionTracer,
	perf_counter_uint64,
	TP_ARGS(
		const char*, cat_arg,
		uint64_t, kernel_object,
		gpa_uint32, counter_index,
		const char*, counter_name,
		uint64_t, value
	),
	TP_FIELDS(
		ctf_string(cat, cat_arg)
		ctf_integer_hex(uint64_t, kernel_object, kernel_object)
		ctf_integer(uint32_t, counter_index, counter_index)
		ctf_string(counter_name, counter_name)
		ctf_integer(uint64_t, value, value)
	)
)

TRACEPOINT_EVENT(
	interceptionTracer,
	perf_counter_float32,
	TP_ARGS(
		const char*, cat_arg,
		uint64_t, kernel_object,
		gpa_uint32, counter_index,
		const char*, counter_name,
		float, value
	),
	TP_FIELDS(
		ctf_string(cat, cat_arg)
		ctf_integer_hex(uint64_t, kernel_object, kernel_object)
		ctf_integer(uint32_t, counter_index, counter_index)
		ctf_string(counter_name, counter_name)
		ctf_float(float, value, value)
	)
)

TRACEPOINT_EVENT(
	interceptionTracer,
	perf_counter_float64,
	TP_ARGS(
		const char*, cat_arg,
		uint64_t, kernel_object,
		gpa_uint32, counter_index,
		const char*, counter_name,
		double, value
	),
	TP_FIELDS(
		ctf_string(cat, cat_arg)
		ctf_integer_hex(uint64_t, kernel_object, kernel_object)
		ctf_integer(uint32_t, counter_index, counter_index)
		ctf_string(counter_name, counter_name)
		ctf_float(double, value, value)
	)
)

#endif /* HSA_TRACEPOINTS_H */

#include <lttng/tracepoint-event.h>
