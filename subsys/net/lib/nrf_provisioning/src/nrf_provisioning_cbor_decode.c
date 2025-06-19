/*
 * Copyright (c) 2025 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
 *
 * Generated using zcbor version 0.9.1
 * https://github.com/NordicSemiconductor/zcbor
 * Generated with a --default-max-qty of CONFIG_NRF_PROVISIONING_CBOR_RECORDS
 */

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include "zcbor_decode.h"
#include "nrf_provisioning_cbor_decode.h"
#include "zcbor_print.h"

#if DEFAULT_MAX_QTY != CONFIG_NRF_PROVISIONING_CBOR_RECORDS
#error "The type file was generated with a different default_max_qty than this file"
#endif

#define log_result(state, result, func)                                                            \
	do {                                                                                       \
		if (!result) {                                                                     \
			zcbor_trace_file(state);                                                   \
			zcbor_log("%s error: %s\r\n", func,                                        \
				  zcbor_error_str(zcbor_peek_error(state)));                       \
		} else {                                                                           \
			zcbor_log("%s success\r\n", func);                                         \
		}                                                                                  \
	} while (0)

static bool decode_at_command(zcbor_state_t *state, struct at_command *result);
static bool decode_repeated_properties_tstrunion(zcbor_state_t *state,
						 struct properties_tstrunion_r *result);
static bool decode_config(zcbor_state_t *state, struct config *result);
static bool decode_command(zcbor_state_t *state, struct command *result);
static bool decode_commands(zcbor_state_t *state, struct commands *result);

static bool decode_at_command(zcbor_state_t *state, struct at_command *result)
{
	zcbor_log("%s\r\n", __func__);

	bool res =
		(((((zcbor_uint32_expect(state, (0)))) &&
		   ((zcbor_tstr_decode(state, (&(*result).at_command_set_command)))) &&
		   ((zcbor_tstr_decode(state, (&(*result).at_command_parameters)))) &&
		   ((zcbor_list_start_decode(state) &&
		     ((zcbor_multi_decode(0, 6, &(*result).at_command_ignore_cme_errors_uint_count,
					  (zcbor_decoder_t *)zcbor_uint32_decode, state,
					  (*&(*result).at_command_ignore_cme_errors_uint),
					  sizeof(uint32_t))) ||
		      (zcbor_list_map_end_force_decode(state), false)) &&
		     zcbor_list_end_decode(state))))));

	if (false) {
		/* For testing that the types of the arguments are correct.
		 * A compiler error here means a bug in zcbor.
		 */
		zcbor_uint32_decode(state, (*&(*result).at_command_ignore_cme_errors_uint));
	}

	log_result(state, res, __func__);
	return res;
}

static bool decode_repeated_properties_tstrunion(zcbor_state_t *state,
						 struct properties_tstrunion_r *result)
{
	zcbor_log("%s\r\n", __func__);
	bool int_res;

	bool res = ((
		((zcbor_tstr_decode(state, (&(*result).config_properties_tstrunion_key)))) &&
		(zcbor_union_start_code(state) &&
		 (int_res =
			  ((((zcbor_tstr_decode(state, (&(*result).properties_tstrunion_tstr)))) &&
			    (((*result).properties_tstrunion_choice = properties_tstrunion_tstr_c),
			     true)) ||
			   (((zcbor_bool_decode(state, (&(*result).properties_tstrunion_bool)))) &&
			    (((*result).properties_tstrunion_choice = properties_tstrunion_bool_c),
			     true)) ||
			   (((zcbor_int32_decode(state, (&(*result).properties_tstrunion_int)))) &&
			    (((*result).properties_tstrunion_choice = properties_tstrunion_int_c),
			     true)) ||
			   (((zcbor_bstr_decode(state, (&(*result).properties_tstrunion_bstr)))) &&
			    (((*result).properties_tstrunion_choice = properties_tstrunion_bstr_c),
			     true))),
		  zcbor_union_end_code(state), int_res))));

	log_result(state, res, __func__);
	return res;
}

static bool decode_config(zcbor_state_t *state, struct config *result)
{
	zcbor_log("%s\r\n", __func__);

	bool res =
		(((((zcbor_uint32_expect(state, (1)))) &&
		   ((zcbor_map_start_decode(state) &&
		     ((zcbor_multi_decode(0, 10, &(*result).properties_tstrunion_count,
					  (zcbor_decoder_t *)decode_repeated_properties_tstrunion,
					  state, (*&(*result).properties_tstrunion),
					  sizeof(struct properties_tstrunion_r))) ||
		      (zcbor_list_map_end_force_decode(state), false)) &&
		     zcbor_map_end_decode(state))))));

	if (false) {
		/* For testing that the types of the arguments are correct.
		 * A compiler error here means a bug in zcbor.
		 */
		decode_repeated_properties_tstrunion(state, (*&(*result).properties_tstrunion));
	}

	log_result(state, res, __func__);
	return res;
}

static bool decode_command(zcbor_state_t *state, struct command *result)
{
	zcbor_log("%s\r\n", __func__);
	bool int_res;

	bool res = ((
		(zcbor_list_start_decode(state) &&
		 ((((zcbor_tstr_decode(state, (&(*result).command_correlation_m)))) &&
		   ((zcbor_union_start_code(state) &&
		     (int_res = ((((decode_at_command(state,
						      (&(*result).command_union_at_command_m)))) &&
				  (((*result).command_union_choice = command_union_at_command_m_c),
				   true)) ||
				 (zcbor_union_elem_code(state) &&
				  (((decode_config(state, (&(*result).command_union_config_m)))) &&
				   (((*result).command_union_choice = command_union_config_m_c),
				    true))) ||
				 (((zcbor_uint32_expect_union(state, (2)))) &&
				  (((*result).command_union_choice = command_union_finished_m_c),
				   true))),
		      zcbor_union_end_code(state), int_res)))) ||
		  (zcbor_list_map_end_force_decode(state), false)) &&
		 zcbor_list_end_decode(state))));

	log_result(state, res, __func__);
	return res;
}

static bool decode_commands(zcbor_state_t *state, struct commands *result)
{
	zcbor_log("%s\r\n", __func__);

	bool res =
		(((zcbor_list_start_decode(state) &&
		   ((zcbor_multi_decode(
			    1, CONFIG_NRF_PROVISIONING_CBOR_RECORDS,
			    &(*result).commands_command_m_count, (zcbor_decoder_t *)decode_command,
			    state, (*&(*result).commands_command_m), sizeof(struct command))) ||
		    (zcbor_list_map_end_force_decode(state), false)) &&
		   zcbor_list_end_decode(state))));

	if (false) {
		/* For testing that the types of the arguments are correct.
		 * A compiler error here means a bug in zcbor.
		 */
		decode_command(state, (*&(*result).commands_command_m));
	}

	log_result(state, res, __func__);
	return res;
}

int cbor_decode_commands(const uint8_t *payload, size_t payload_len, struct commands *result,
			 size_t *payload_len_out)
{
	zcbor_state_t states[7];

	return zcbor_entry_function(payload, payload_len, (void *)result, payload_len_out, states,
				    (zcbor_decoder_t *)decode_commands,
				    sizeof(states) / sizeof(zcbor_state_t), 1);
}
