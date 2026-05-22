#pragma once


// Avoid destruction for thread safety.
// Only enable this with clang.
#if defined(__clang__)
#ifndef ACONFIG_NO_DESTROY
#define ACONFIG_NO_DESTROY [[clang::no_destroy]]
#endif
#else
#ifndef _MSC_VER
#warning "not built with clang disable no_destroy"
#endif
#ifndef ACONFIG_NO_DESTROY
#define ACONFIG_NO_DESTROY
#endif
#endif



#ifdef __cplusplus

#include <memory>

namespace com::android::bluetooth::flags {

class flag_provider_interface {
public:
    virtual ~flag_provider_interface() = default;
    virtual bool a2dp_adjust_sbc_bitpool() = 0;
    virtual bool a2dp_cancel_acceptor_alarm_for_avdt_init() = 0;
    virtual bool a2dp_delay_disconnect() = 0;
    virtual bool a2dp_delay_report_in_dumpsys() = 0;
    virtual bool a2dp_disconnect_reason_api() = 0;
    virtual bool a2dp_fmq_read_exact() = 0;
    virtual bool a2dp_lhdc_api() = 0;
    virtual bool a2dp_pm_app_id() = 0;
    virtual bool a2dp_reject_sho_request() = 0;
    virtual bool a2dp_sbc_underflow_recovery() = 0;
    virtual bool a2dp_set_configuration_during_discovery() = 0;
    virtual bool a2dp_source_null_fixed_queue() = 0;
    virtual bool abs_volume_sdp_conflict() = 0;
    virtual bool acl_fix_in_and_out_connection_reqs() = 0;
    virtual bool adapter_suspend_advertisement() = 0;
    virtual bool adapter_suspend_discoverability() = 0;
    virtual bool adapter_suspend_mgmt() = 0;
    virtual bool add_bond_loss_reason() = 0;
    virtual bool add_hop_to_event_callback() = 0;
    virtual bool add_profile_as_intent_extra() = 0;
    virtual bool adm_centralize_active_device_handling() = 0;
    virtual bool adm_remove_handling_wired() = 0;
    virtual bool adm_unset_others_on_hfp_changed() = 0;
    virtual bool aics_api() = 0;
    virtual bool allow_rearm_if_suspend_scan_params_used() = 0;
    virtual bool allow_switching_hid_and_hogp() = 0;
    virtual bool always_set_identity_addr() = 0;
    virtual bool asha_omit_gatt_after_svc_changed() = 0;
    virtual bool avdt_close_on_start_failure_bad_state() = 0;
    virtual bool avdt_wait_for_initial_delay_report_as_initiator() = 0;
    virtual bool avoid_ctkd_for_temp_pairing() = 0;
    virtual bool avoid_l2c_processing_while_stack_shutdown() = 0;
    virtual bool avrcp_16_default() = 0;
    virtual bool batch_scan_support_check() = 0;
    virtual bool ble_rnr_when_connected() = 0;
    virtual bool bluetooth_power_telemetry() = 0;
    virtual bool bond_loss_transport_check() = 0;
    virtual bool bond_state_machine_looper() = 0;
    virtual bool bonding_initiator_state_reset() = 0;
    virtual bool bqr_common_part_unified_length() = 0;
    virtual bool br_edr_discover_gatt_services_over_gatt() = 0;
    virtual bool broadcast_transport_type_on_reset() = 0;
    virtual bool bt_offload_socket_api() = 0;
    virtual bool bt_socket_api_l2cap_cid() = 0;
    virtual bool btsec_check_controller_sc_support() = 0;
    virtual bool btsec_cycle_irks() = 0;
    virtual bool call_sdp_free_in_main_thread() = 0;
    virtual bool channel_sounding() = 0;
    virtual bool channel_sounding_25q2_apis() = 0;
    virtual bool channel_sounding_offload() = 0;
    virtual bool check_call_state_atd() = 0;
    virtual bool check_l2c_conn_status_before_param_validation() = 0;
    virtual bool check_peer_hf_indicator() = 0;
    virtual bool clear_pairing_state_when_no_devrec() = 0;
    virtual bool complete_disc_if_no_rnr() = 0;
    virtual bool conclude_le_pairing_immediately() = 0;
    virtual bool concurrent_incoming_outgoing_pairing() = 0;
    virtual bool consider_l2c_header_bytes_for_mps_selection() = 0;
    virtual bool consistent_battery_level() = 0;
    virtual bool continue_queued_command_after_discovery() = 0;
    virtual bool delay_jv_pm_idle() = 0;
    virtual bool delay_offload_le_coc_connection_ind() = 0;
    virtual bool delay_sniff_subrating() = 0;
    virtual bool directed_advertising_api() = 0;
    virtual bool disconnect_acl_on_gatt_timeout() = 0;
    virtual bool disconnect_acls_by_bredr_disabled() = 0;
    virtual bool distance_measurement_thread() = 0;
    virtual bool do_not_dump_devices_from_adapter_properties() = 0;
    virtual bool do_not_hardcode_tmap_role_mask() = 0;
    virtual bool donot_collide_with_closed_port() = 0;
    virtual bool donot_mandate_auth_along_with_encryption() = 0;
    virtual bool donot_pm_classic_on_le_traffic() = 0;
    virtual bool dont_send_hci_disconnect_repeatedly() = 0;
    virtual bool downgrade_to_basic_mode_on_no_info_resp() = 0;
    virtual bool dsa_use_codec_extensibility() = 0;
    virtual bool dump_without_promise_timeout() = 0;
    virtual bool early_incoming_hid_connection() = 0;
    virtual bool enable_battery_level_update_only_through_hf_indicator() = 0;
    virtual bool encryption_change_broadcast() = 0;
    virtual bool end_outgoing_call_on_chld() = 0;
    virtual bool ensure_acl_connection_is_removed_from_pending_list() = 0;
    virtual bool extend_and_randomize_role_switch_delay() = 0;
    virtual bool fix_buf_len_check_for_first_k_frame() = 0;
    virtual bool fix_event_handler_reg_and_dereg() = 0;
    virtual bool fix_hfp_qual_1_9() = 0;
    virtual bool fix_hfp_rfcomm_collision_state_machine_error() = 0;
    virtual bool fix_lecoc_socket_available() = 0;
    virtual bool fix_ongoing_rnr_while_bonding() = 0;
    virtual bool fix_private_gatt_advertisement() = 0;
    virtual bool fix_race_in_orphaned_acls() = 0;
    virtual bool fix_socket_connection_failed_no_callback() = 0;
    virtual bool fix_started_module_race() = 0;
    virtual bool fix_unhandled_bqr_subevent() = 0;
    virtual bool fix_use_after_object_destroyed() = 0;
    virtual bool flag_handle_hci_error_controller_busy() = 0;
    virtual bool floss_separate_host_privacy_and_llprivacy() = 0;
    virtual bool gatt_clear_cache_on_factory_reset() = 0;
    virtual bool gatt_discovery_is_non_opportunistic_client() = 0;
    virtual bool gatt_failure_callback_on_cancel() = 0;
    virtual bool gatt_messaging_permissions() = 0;
    virtual bool gatt_multi_bearer_connections() = 0;
    virtual bool gatt_multi_bearer_transactions() = 0;
    virtual bool gatt_offload_api() = 0;
    virtual bool gen_key_missing_evt_only_from_iocapreq() = 0;
    virtual bool get_all_element_attributes_empty() = 0;
    virtual bool get_profile_oneway() = 0;
    virtual bool get_svc_uuids_bugfix() = 0;
    virtual bool get_svc_uuids_from_ble_adv_data() = 0;
    virtual bool graceful_disable_without_message() = 0;
    virtual bool handle_delivery_sending_failure_events() = 0;
    virtual bool handle_encryption_fail_before_sdp_when_paring() = 0;
    virtual bool hap_on_main_looper() = 0;
    virtual bool hap_safely_erase_pending_operation_timeout() = 0;
    virtual bool hci_instance_name_use_injected() = 0;
    virtual bool hci_vendor_specific_extension() = 0;
    virtual bool hfp_client_disconnecting_state() = 0;
    virtual bool hfp_sco_state_reset_when_profile_restart() = 0;
    virtual bool hh_state_update_race_fix() = 0;
    virtual bool hid_connection_timeout_in_jni_thread() = 0;
    virtual bool hidd_handle_set_protocol_before_interrupt_connected() = 0;
    virtual bool hidh_close_in_jni_thread() = 0;
    virtual bool hogp_direct_connection_upgrade() = 0;
    virtual bool hogp_encryption_collision() = 0;
    virtual bool hold_conference_call_from_remote() = 0;
    virtual bool idempotent_direct_connect_add() = 0;
    virtual bool identity_address_type_api() = 0;
    virtual bool identity_to_pseudo_addr() = 0;
    virtual bool ignore_auth_req_when_collision_timer_active() = 0;
    virtual bool ignore_le_smp_conn_when_sm_over_br_progress() = 0;
    virtual bool ignore_message_sms_disallowed() = 0;
    virtual bool ignore_multiple_connect_request_in_bt_services() = 0;
    virtual bool ignore_unrelated_cancel_bond() = 0;
    virtual bool immediate_encryption_after_pairing() = 0;
    virtual bool implement_get_image_from_descriptor_for_cover_art() = 0;
    virtual bool increase_contact_image_resolution() = 0;
    virtual bool indicate_rfcomm_connection_complete_after_msc() = 0;
    virtual bool initial_conn_params_p1() = 0;
    virtual bool invalidate_hci_handle_on_acl_removal() = 0;
    virtual bool irk_scan_bond_check_update() = 0;
    virtual bool key_missing_count_api() = 0;
    virtual bool key_missing_public() = 0;
    virtual bool l2c_not_cancel_timeout() = 0;
    virtual bool l2cap_improve_segmented_sdu() = 0;
    virtual bool ldac_rate_control() = 0;
    virtual bool le_address_map_update() = 0;
    virtual bool le_ase_read_multiple_variable() = 0;
    virtual bool le_audio_update_config_preference_to_hal() = 0;
    virtual bool le_scan_msft_support() = 0;
    virtual bool le_subrate_api() = 0;
    virtual bool le_subrate_manager() = 0;
    virtual bool leaudio_add_opus_codec_type() = 0;
    virtual bool leaudio_add_opus_hi_res_codec_type() = 0;
    virtual bool leaudio_add_opus_hi_res_codec_type_api() = 0;
    virtual bool leaudio_bis_sync_control() = 0;
    virtual bool leaudio_broadcast_allow_monitoring_on_resume() = 0;
    virtual bool leaudio_broadcast_api_get_local_metadata() = 0;
    virtual bool leaudio_broadcast_api_manage_primary_group() = 0;
    virtual bool leaudio_broadcast_config_data_path_before_set_iso_data_path() = 0;
    virtual bool leaudio_broadcast_fix_autonomous_source_adding() = 0;
    virtual bool leaudio_broadcast_monitor_source_sync_status() = 0;
    virtual bool leaudio_broadcast_remove_sink_metadata_on_switch_to_local() = 0;
    virtual bool leaudio_broadcast_simplify_set_bcast_code() = 0;
    virtual bool leaudio_broadcast_source_channel_map_classification() = 0;
    virtual bool leaudio_broadcast_volume_control_for_connected_devices() = 0;
    virtual bool leaudio_check_ecosystem_base_interval_support() = 0;
    virtual bool leaudio_config_profile_enabling() = 0;
    virtual bool leaudio_connection_subrating() = 0;
    virtual bool leaudio_dev_options_respect_profile_sysprops() = 0;
    virtual bool leaudio_disable_broadcast_for_hap_device() = 0;
    virtual bool leaudio_do_not_set_autoconnecting_on_connected_device() = 0;
    virtual bool leaudio_dynamic_data_path_change() = 0;
    virtual bool leaudio_dynamic_direction_opening() = 0;
    virtual bool leaudio_fix_stop_reconfiguration_timeout() = 0;
    virtual bool leaudio_improve_switching_le_audio_devices() = 0;
    virtual bool leaudio_intent_broadcast_in_state_machine_cleanup() = 0;
    virtual bool leaudio_mono_location_errata_api() = 0;
    virtual bool leaudio_multiple_vocs_instances_api() = 0;
    virtual bool leaudio_peripheral_feature() = 0;
    virtual bool leaudio_set_codec_config_preference() = 0;
    virtual bool leaudio_use_aggressive_params() = 0;
    virtual bool leaudio_use_context_type_manager() = 0;
    virtual bool leaudio_use_game_sonification_as_regular_sonification() = 0;
    virtual bool lhdc_codec_support() = 0;
    virtual bool link_status_api() = 0;
    virtual bool maintain_call_index_after_conference() = 0;
    virtual bool make_socket_read_behavior_consistent() = 0;
    virtual bool map_client_check_access_permission() = 0;
    virtual bool map_continue_operation() = 0;
    virtual bool map_mime_multipart() = 0;
    virtual bool merge_call_with_held_conference() = 0;
    virtual bool metadata_api_inactive_audio_device_upon_connection() = 0;
    virtual bool metadata_api_microphone_for_call_enabled() = 0;
    virtual bool microphone_mute_status_sync() = 0;
    virtual bool mode_change_before_sco_unpark() = 0;
    virtual bool monitor_read_flag_on_offloaded_socket() = 0;
    virtual bool msft_addr_tracking_quirk() = 0;
    virtual bool non_bonded_device_properties() = 0;
    virtual bool non_conference_call_hangup() = 0;
    virtual bool non_zero_local_irk() = 0;
    virtual bool not_delete_locked_message() = 0;
    virtual bool nrpa_non_connectable_adv() = 0;
    virtual bool on_to_ble_on_via_off() = 0;
    virtual bool only_broadcast_to_local_user() = 0;
    virtual bool only_start_scan_during_ble_on() = 0;
    virtual bool opp_check_content_uri_permissions() = 0;
    virtual bool opp_device_picker_extra_intent_apis() = 0;
    virtual bool original_address_filter_match() = 0;
    virtual bool pairing_collision_with_same_device() = 0;
    virtual bool pbap_cleanup_use_handler() = 0;
    virtual bool pbap_client_check_access_permission() = 0;
    virtual bool pbap_client_contacts_caching() = 0;
    virtual bool pbap_limit_call_log() = 0;
    virtual bool preload_gatt_database() = 0;
    virtual bool prevent_adding_both_pseudo_and_identity_addr() = 0;
    virtual bool prevent_storage_access_without_gd_running() = 0;
    virtual bool prioritized_in_ear_routing() = 0;
    virtual bool protect_dumpsys_during_stack_shutdown() = 0;
    virtual bool qc_aptx_codec_negotiation() = 0;
    virtual bool qc_prioritize_lc3_codec() = 0;
    virtual bool qc_send_error_at_bcc_ibr_disabled() = 0;
    virtual bool queue_dis_requests() = 0;
    virtual bool read_ppcp_only_for_success() = 0;
    virtual bool read_rssi_throttling() = 0;
    virtual bool reboke_permission_on_unbond() = 0;
    virtual bool reconnect_on_hogp_connection_failure() = 0;
    virtual bool ref_counted_native_wakelock() = 0;
    virtual bool refactor_saving_messages_and_metadata() = 0;
    virtual bool reject_bond_request_during_bonding() = 0;
    virtual bool release_port_in_bta_ag_rfc_fail_before_reset_context() = 0;
    virtual bool remove_address_cache_from_ble_scanner() = 0;
    virtual bool remove_device_with_connection_manager() = 0;
    virtual bool remove_handler_clear() = 0;
    virtual bool remove_hop_from_le_adv_set_term() = 0;
    virtual bool replace_message_loop_thread_with_gd_handler() = 0;
    virtual bool reset_collision_state_on_encryption() = 0;
    virtual bool reset_security_flags_on_pairing_failure() = 0;
    virtual bool reset_service_change_ind_counter() = 0;
    virtual bool reset_state_when_removing_non_connected_hid_device() = 0;
    virtual bool resolve_address_for_adv_report() = 0;
    virtual bool retain_address_type() = 0;
    virtual bool return_correct_ble_state() = 0;
    virtual bool rfcomm_fix_bta_ag_rfc_acp_open_error() = 0;
    virtual bool rfcomm_fix_mux_collision_handling() = 0;
    virtual bool rnr_directly_call_gap_over_le() = 0;
    virtual bool rnr_validate_page_scan_repetition_mode() = 0;
    virtual bool role_switch_after_encryption() = 0;
    virtual bool rssi_scan_filter() = 0;
    virtual bool same_handler_for_all_modules() = 0;
    virtual bool save_cache_for_bonded_device() = 0;
    virtual bool scan_controller_thread() = 0;
    virtual bool sco_managed_by_audio_remove_hfp_hal() = 0;
    virtual bool sco_state_machine_cleanup() = 0;
    virtual bool sco_state_machine_update_in_codec_state() = 0;
    virtual bool sdp_reset_transport_status_if_disconnect() = 0;
    virtual bool send_ok_clcc_before_slc() = 0;
    virtual bool send_ok_on_no_action_on_chld() = 0;
    virtual bool send_opp_device_picker_extra_intent() = 0;
    virtual bool separate_encryption_queue() = 0;
    virtual bool service_discovery_on_connected_transport() = 0;
    virtual bool service_rediscovery_fix() = 0;
    virtual bool set_a2dp_active_device_through_adapter_service() = 0;
    virtual bool set_component_available_fix() = 0;
    virtual bool set_max_data_length_for_lecoc() = 0;
    virtual bool set_ptr_null_after_free() = 0;
    virtual bool settings_can_control_hap_preset() = 0;
    virtual bool shutdown_main_thread_before_cleanup() = 0;
    virtual bool simpler_hid_connection_policy() = 0;
    virtual bool skip_excess_name_discovery() = 0;
    virtual bool skip_unknown_robust_caching() = 0;
    virtual bool smp_connection_status_handling_when_no_acl() = 0;
    virtual bool sniff_offload_with_vsc_based_control() = 0;
    virtual bool snoop_logger_save_multiple_snoop_logs() = 0;
    virtual bool socket_settings_api() = 0;
    virtual bool stack_sdp_detect_nil_property_type() = 0;
    virtual bool start_discover_service_changed() = 0;
    virtual bool start_leaudio_subrate_for_active_set_only() = 0;
    virtual bool stop_le_scan_system_suspend() = 0;
    virtual bool support_bluetooth_quality_report_v6() = 0;
    virtual bool support_metadata_device_types_apis() = 0;
    virtual bool support_passive_scanning() = 0;
    virtual bool support_zoomed_in_icon_metadata() = 0;
    virtual bool synchronize_codec_preferences_and_priority() = 0;
    virtual bool synchronize_preset_can_timeout() = 0;
    virtual bool system_server_messenger() = 0;
    virtual bool tbs_gatt_no_longer_calls_framework() = 0;
    virtual bool tbs_set_lea_from_btservice() = 0;
    virtual bool temporary_pairing_tracking() = 0;
    virtual bool trigger_sec_proc_on_inc_access_req() = 0;
    virtual bool unix_file_socket_creation_failure() = 0;
    virtual bool unrelated_device_smp_cancellation() = 0;
    virtual bool update_cod_if_missing() = 0;
    virtual bool upgrade_le_scan_only_screen_on() = 0;
    virtual bool upgrade_temp_bonding_on_auth_req() = 0;
    virtual bool use_data_store_storage() = 0;
    virtual bool use_entire_message_handle() = 0;
    virtual bool use_returned_absolute_volume() = 0;
    virtual bool use_shared_promise_for_le_address_manager() = 0;
    virtual bool user_restriction_refactor() = 0;
    virtual bool user_visible_on_user_starting() = 0;
    virtual bool validate_connection_policy_before_accepting_connection() = 0;
    virtual bool vcp_handle_group_id_internally() = 0;
    virtual bool vcp_on_main_looper() = 0;
    virtual bool voice_recognition_fixes() = 0;
    virtual bool wait_hid_disconnect_before_marking_unused() = 0;
    virtual bool watch_device_override_airplane_mode() = 0;
};

ACONFIG_NO_DESTROY extern std::unique_ptr<flag_provider_interface> provider_;


inline bool a2dp_adjust_sbc_bitpool() {
    return provider_->a2dp_adjust_sbc_bitpool();
}
inline bool a2dp_cancel_acceptor_alarm_for_avdt_init() {
    return provider_->a2dp_cancel_acceptor_alarm_for_avdt_init();
}
inline bool a2dp_delay_disconnect() {
    return provider_->a2dp_delay_disconnect();
}
inline bool a2dp_delay_report_in_dumpsys() {
    return provider_->a2dp_delay_report_in_dumpsys();
}
inline bool a2dp_disconnect_reason_api() {
    return provider_->a2dp_disconnect_reason_api();
}
inline bool a2dp_fmq_read_exact() {
    return provider_->a2dp_fmq_read_exact();
}
inline bool a2dp_lhdc_api() {
    return provider_->a2dp_lhdc_api();
}
inline bool a2dp_pm_app_id() {
    return provider_->a2dp_pm_app_id();
}
inline bool a2dp_reject_sho_request() {
    return provider_->a2dp_reject_sho_request();
}
inline bool a2dp_sbc_underflow_recovery() {
    return provider_->a2dp_sbc_underflow_recovery();
}
inline bool a2dp_set_configuration_during_discovery() {
    return provider_->a2dp_set_configuration_during_discovery();
}
inline bool a2dp_source_null_fixed_queue() {
    return provider_->a2dp_source_null_fixed_queue();
}
inline bool abs_volume_sdp_conflict() {
    return provider_->abs_volume_sdp_conflict();
}
inline bool acl_fix_in_and_out_connection_reqs() {
    return provider_->acl_fix_in_and_out_connection_reqs();
}
inline bool adapter_suspend_advertisement() {
    return provider_->adapter_suspend_advertisement();
}
inline bool adapter_suspend_discoverability() {
    return provider_->adapter_suspend_discoverability();
}
inline bool adapter_suspend_mgmt() {
    return provider_->adapter_suspend_mgmt();
}
inline bool add_bond_loss_reason() {
    return provider_->add_bond_loss_reason();
}
inline bool add_hop_to_event_callback() {
    return provider_->add_hop_to_event_callback();
}
inline bool add_profile_as_intent_extra() {
    return provider_->add_profile_as_intent_extra();
}
inline bool adm_centralize_active_device_handling() {
    return provider_->adm_centralize_active_device_handling();
}
inline bool adm_remove_handling_wired() {
    return provider_->adm_remove_handling_wired();
}
inline bool adm_unset_others_on_hfp_changed() {
    return provider_->adm_unset_others_on_hfp_changed();
}
inline bool aics_api() {
    return provider_->aics_api();
}
inline bool allow_rearm_if_suspend_scan_params_used() {
    return provider_->allow_rearm_if_suspend_scan_params_used();
}
inline bool allow_switching_hid_and_hogp() {
    return provider_->allow_switching_hid_and_hogp();
}
inline bool always_set_identity_addr() {
    return provider_->always_set_identity_addr();
}
inline bool asha_omit_gatt_after_svc_changed() {
    return provider_->asha_omit_gatt_after_svc_changed();
}
inline bool avdt_close_on_start_failure_bad_state() {
    return provider_->avdt_close_on_start_failure_bad_state();
}
inline bool avdt_wait_for_initial_delay_report_as_initiator() {
    return provider_->avdt_wait_for_initial_delay_report_as_initiator();
}
inline bool avoid_ctkd_for_temp_pairing() {
    return provider_->avoid_ctkd_for_temp_pairing();
}
inline bool avoid_l2c_processing_while_stack_shutdown() {
    return provider_->avoid_l2c_processing_while_stack_shutdown();
}
inline bool avrcp_16_default() {
    return provider_->avrcp_16_default();
}
inline bool batch_scan_support_check() {
    return provider_->batch_scan_support_check();
}
inline bool ble_rnr_when_connected() {
    return provider_->ble_rnr_when_connected();
}
inline bool bluetooth_power_telemetry() {
    return provider_->bluetooth_power_telemetry();
}
inline bool bond_loss_transport_check() {
    return provider_->bond_loss_transport_check();
}
inline bool bond_state_machine_looper() {
    return provider_->bond_state_machine_looper();
}
inline bool bonding_initiator_state_reset() {
    return provider_->bonding_initiator_state_reset();
}
inline bool bqr_common_part_unified_length() {
    return provider_->bqr_common_part_unified_length();
}
inline bool br_edr_discover_gatt_services_over_gatt() {
    return provider_->br_edr_discover_gatt_services_over_gatt();
}
inline bool broadcast_transport_type_on_reset() {
    return provider_->broadcast_transport_type_on_reset();
}
inline bool bt_offload_socket_api() {
    return provider_->bt_offload_socket_api();
}
inline bool bt_socket_api_l2cap_cid() {
    return provider_->bt_socket_api_l2cap_cid();
}
inline bool btsec_check_controller_sc_support() {
    return provider_->btsec_check_controller_sc_support();
}
inline bool btsec_cycle_irks() {
    return provider_->btsec_cycle_irks();
}
inline bool call_sdp_free_in_main_thread() {
    return provider_->call_sdp_free_in_main_thread();
}
inline bool channel_sounding() {
    return provider_->channel_sounding();
}
inline bool channel_sounding_25q2_apis() {
    return provider_->channel_sounding_25q2_apis();
}
inline bool channel_sounding_offload() {
    return provider_->channel_sounding_offload();
}
inline bool check_call_state_atd() {
    return provider_->check_call_state_atd();
}
inline bool check_l2c_conn_status_before_param_validation() {
    return provider_->check_l2c_conn_status_before_param_validation();
}
inline bool check_peer_hf_indicator() {
    return provider_->check_peer_hf_indicator();
}
inline bool clear_pairing_state_when_no_devrec() {
    return provider_->clear_pairing_state_when_no_devrec();
}
inline bool complete_disc_if_no_rnr() {
    return provider_->complete_disc_if_no_rnr();
}
inline bool conclude_le_pairing_immediately() {
    return provider_->conclude_le_pairing_immediately();
}
inline bool concurrent_incoming_outgoing_pairing() {
    return provider_->concurrent_incoming_outgoing_pairing();
}
inline bool consider_l2c_header_bytes_for_mps_selection() {
    return provider_->consider_l2c_header_bytes_for_mps_selection();
}
inline bool consistent_battery_level() {
    return provider_->consistent_battery_level();
}
inline bool continue_queued_command_after_discovery() {
    return provider_->continue_queued_command_after_discovery();
}
inline bool delay_jv_pm_idle() {
    return provider_->delay_jv_pm_idle();
}
inline bool delay_offload_le_coc_connection_ind() {
    return provider_->delay_offload_le_coc_connection_ind();
}
inline bool delay_sniff_subrating() {
    return provider_->delay_sniff_subrating();
}
inline bool directed_advertising_api() {
    return provider_->directed_advertising_api();
}
inline bool disconnect_acl_on_gatt_timeout() {
    return provider_->disconnect_acl_on_gatt_timeout();
}
inline bool disconnect_acls_by_bredr_disabled() {
    return provider_->disconnect_acls_by_bredr_disabled();
}
inline bool distance_measurement_thread() {
    return provider_->distance_measurement_thread();
}
inline bool do_not_dump_devices_from_adapter_properties() {
    return provider_->do_not_dump_devices_from_adapter_properties();
}
inline bool do_not_hardcode_tmap_role_mask() {
    return provider_->do_not_hardcode_tmap_role_mask();
}
inline bool donot_collide_with_closed_port() {
    return provider_->donot_collide_with_closed_port();
}
inline bool donot_mandate_auth_along_with_encryption() {
    return provider_->donot_mandate_auth_along_with_encryption();
}
inline bool donot_pm_classic_on_le_traffic() {
    return provider_->donot_pm_classic_on_le_traffic();
}
inline bool dont_send_hci_disconnect_repeatedly() {
    return provider_->dont_send_hci_disconnect_repeatedly();
}
inline bool downgrade_to_basic_mode_on_no_info_resp() {
    return provider_->downgrade_to_basic_mode_on_no_info_resp();
}
inline bool dsa_use_codec_extensibility() {
    return provider_->dsa_use_codec_extensibility();
}
inline bool dump_without_promise_timeout() {
    return provider_->dump_without_promise_timeout();
}
inline bool early_incoming_hid_connection() {
    return provider_->early_incoming_hid_connection();
}
inline bool enable_battery_level_update_only_through_hf_indicator() {
    return provider_->enable_battery_level_update_only_through_hf_indicator();
}
inline bool encryption_change_broadcast() {
    return provider_->encryption_change_broadcast();
}
inline bool end_outgoing_call_on_chld() {
    return provider_->end_outgoing_call_on_chld();
}
inline bool ensure_acl_connection_is_removed_from_pending_list() {
    return provider_->ensure_acl_connection_is_removed_from_pending_list();
}
inline bool extend_and_randomize_role_switch_delay() {
    return provider_->extend_and_randomize_role_switch_delay();
}
inline bool fix_buf_len_check_for_first_k_frame() {
    return provider_->fix_buf_len_check_for_first_k_frame();
}
inline bool fix_event_handler_reg_and_dereg() {
    return provider_->fix_event_handler_reg_and_dereg();
}
inline bool fix_hfp_qual_1_9() {
    return provider_->fix_hfp_qual_1_9();
}
inline bool fix_hfp_rfcomm_collision_state_machine_error() {
    return provider_->fix_hfp_rfcomm_collision_state_machine_error();
}
inline bool fix_lecoc_socket_available() {
    return provider_->fix_lecoc_socket_available();
}
inline bool fix_ongoing_rnr_while_bonding() {
    return provider_->fix_ongoing_rnr_while_bonding();
}
inline bool fix_private_gatt_advertisement() {
    return provider_->fix_private_gatt_advertisement();
}
inline bool fix_race_in_orphaned_acls() {
    return provider_->fix_race_in_orphaned_acls();
}
inline bool fix_socket_connection_failed_no_callback() {
    return provider_->fix_socket_connection_failed_no_callback();
}
inline bool fix_started_module_race() {
    return provider_->fix_started_module_race();
}
inline bool fix_unhandled_bqr_subevent() {
    return provider_->fix_unhandled_bqr_subevent();
}
inline bool fix_use_after_object_destroyed() {
    return provider_->fix_use_after_object_destroyed();
}
inline bool flag_handle_hci_error_controller_busy() {
    return provider_->flag_handle_hci_error_controller_busy();
}
inline bool floss_separate_host_privacy_and_llprivacy() {
    return provider_->floss_separate_host_privacy_and_llprivacy();
}
inline bool gatt_clear_cache_on_factory_reset() {
    return provider_->gatt_clear_cache_on_factory_reset();
}
inline bool gatt_discovery_is_non_opportunistic_client() {
    return provider_->gatt_discovery_is_non_opportunistic_client();
}
inline bool gatt_failure_callback_on_cancel() {
    return provider_->gatt_failure_callback_on_cancel();
}
inline bool gatt_messaging_permissions() {
    return provider_->gatt_messaging_permissions();
}
inline bool gatt_multi_bearer_connections() {
    return provider_->gatt_multi_bearer_connections();
}
inline bool gatt_multi_bearer_transactions() {
    return provider_->gatt_multi_bearer_transactions();
}
inline bool gatt_offload_api() {
    return provider_->gatt_offload_api();
}
inline bool gen_key_missing_evt_only_from_iocapreq() {
    return provider_->gen_key_missing_evt_only_from_iocapreq();
}
inline bool get_all_element_attributes_empty() {
    return provider_->get_all_element_attributes_empty();
}
inline bool get_profile_oneway() {
    return provider_->get_profile_oneway();
}
inline bool get_svc_uuids_bugfix() {
    return provider_->get_svc_uuids_bugfix();
}
inline bool get_svc_uuids_from_ble_adv_data() {
    return provider_->get_svc_uuids_from_ble_adv_data();
}
inline bool graceful_disable_without_message() {
    return provider_->graceful_disable_without_message();
}
inline bool handle_delivery_sending_failure_events() {
    return provider_->handle_delivery_sending_failure_events();
}
inline bool handle_encryption_fail_before_sdp_when_paring() {
    return provider_->handle_encryption_fail_before_sdp_when_paring();
}
inline bool hap_on_main_looper() {
    return provider_->hap_on_main_looper();
}
inline bool hap_safely_erase_pending_operation_timeout() {
    return provider_->hap_safely_erase_pending_operation_timeout();
}
inline bool hci_instance_name_use_injected() {
    return provider_->hci_instance_name_use_injected();
}
inline bool hci_vendor_specific_extension() {
    return provider_->hci_vendor_specific_extension();
}
inline bool hfp_client_disconnecting_state() {
    return provider_->hfp_client_disconnecting_state();
}
inline bool hfp_sco_state_reset_when_profile_restart() {
    return provider_->hfp_sco_state_reset_when_profile_restart();
}
inline bool hh_state_update_race_fix() {
    return provider_->hh_state_update_race_fix();
}
inline bool hid_connection_timeout_in_jni_thread() {
    return provider_->hid_connection_timeout_in_jni_thread();
}
inline bool hidd_handle_set_protocol_before_interrupt_connected() {
    return provider_->hidd_handle_set_protocol_before_interrupt_connected();
}
inline bool hidh_close_in_jni_thread() {
    return provider_->hidh_close_in_jni_thread();
}
inline bool hogp_direct_connection_upgrade() {
    return provider_->hogp_direct_connection_upgrade();
}
inline bool hogp_encryption_collision() {
    return provider_->hogp_encryption_collision();
}
inline bool hold_conference_call_from_remote() {
    return provider_->hold_conference_call_from_remote();
}
inline bool idempotent_direct_connect_add() {
    return provider_->idempotent_direct_connect_add();
}
inline bool identity_address_type_api() {
    return provider_->identity_address_type_api();
}
inline bool identity_to_pseudo_addr() {
    return provider_->identity_to_pseudo_addr();
}
inline bool ignore_auth_req_when_collision_timer_active() {
    return provider_->ignore_auth_req_when_collision_timer_active();
}
inline bool ignore_le_smp_conn_when_sm_over_br_progress() {
    return provider_->ignore_le_smp_conn_when_sm_over_br_progress();
}
inline bool ignore_message_sms_disallowed() {
    return provider_->ignore_message_sms_disallowed();
}
inline bool ignore_multiple_connect_request_in_bt_services() {
    return provider_->ignore_multiple_connect_request_in_bt_services();
}
inline bool ignore_unrelated_cancel_bond() {
    return provider_->ignore_unrelated_cancel_bond();
}
inline bool immediate_encryption_after_pairing() {
    return provider_->immediate_encryption_after_pairing();
}
inline bool implement_get_image_from_descriptor_for_cover_art() {
    return provider_->implement_get_image_from_descriptor_for_cover_art();
}
inline bool increase_contact_image_resolution() {
    return provider_->increase_contact_image_resolution();
}
inline bool indicate_rfcomm_connection_complete_after_msc() {
    return provider_->indicate_rfcomm_connection_complete_after_msc();
}
inline bool initial_conn_params_p1() {
    return provider_->initial_conn_params_p1();
}
inline bool invalidate_hci_handle_on_acl_removal() {
    return provider_->invalidate_hci_handle_on_acl_removal();
}
inline bool irk_scan_bond_check_update() {
    return provider_->irk_scan_bond_check_update();
}
inline bool key_missing_count_api() {
    return provider_->key_missing_count_api();
}
inline bool key_missing_public() {
    return provider_->key_missing_public();
}
inline bool l2c_not_cancel_timeout() {
    return provider_->l2c_not_cancel_timeout();
}
inline bool l2cap_improve_segmented_sdu() {
    return provider_->l2cap_improve_segmented_sdu();
}
inline bool ldac_rate_control() {
    return provider_->ldac_rate_control();
}
inline bool le_address_map_update() {
    return provider_->le_address_map_update();
}
inline bool le_ase_read_multiple_variable() {
    return provider_->le_ase_read_multiple_variable();
}
inline bool le_audio_update_config_preference_to_hal() {
    return provider_->le_audio_update_config_preference_to_hal();
}
inline bool le_scan_msft_support() {
    return provider_->le_scan_msft_support();
}
inline bool le_subrate_api() {
    return provider_->le_subrate_api();
}
inline bool le_subrate_manager() {
    return provider_->le_subrate_manager();
}
inline bool leaudio_add_opus_codec_type() {
    return provider_->leaudio_add_opus_codec_type();
}
inline bool leaudio_add_opus_hi_res_codec_type() {
    return provider_->leaudio_add_opus_hi_res_codec_type();
}
inline bool leaudio_add_opus_hi_res_codec_type_api() {
    return provider_->leaudio_add_opus_hi_res_codec_type_api();
}
inline bool leaudio_bis_sync_control() {
    return provider_->leaudio_bis_sync_control();
}
inline bool leaudio_broadcast_allow_monitoring_on_resume() {
    return provider_->leaudio_broadcast_allow_monitoring_on_resume();
}
inline bool leaudio_broadcast_api_get_local_metadata() {
    return provider_->leaudio_broadcast_api_get_local_metadata();
}
inline bool leaudio_broadcast_api_manage_primary_group() {
    return provider_->leaudio_broadcast_api_manage_primary_group();
}
inline bool leaudio_broadcast_config_data_path_before_set_iso_data_path() {
    return provider_->leaudio_broadcast_config_data_path_before_set_iso_data_path();
}
inline bool leaudio_broadcast_fix_autonomous_source_adding() {
    return provider_->leaudio_broadcast_fix_autonomous_source_adding();
}
inline bool leaudio_broadcast_monitor_source_sync_status() {
    return provider_->leaudio_broadcast_monitor_source_sync_status();
}
inline bool leaudio_broadcast_remove_sink_metadata_on_switch_to_local() {
    return provider_->leaudio_broadcast_remove_sink_metadata_on_switch_to_local();
}
inline bool leaudio_broadcast_simplify_set_bcast_code() {
    return provider_->leaudio_broadcast_simplify_set_bcast_code();
}
inline bool leaudio_broadcast_source_channel_map_classification() {
    return provider_->leaudio_broadcast_source_channel_map_classification();
}
inline bool leaudio_broadcast_volume_control_for_connected_devices() {
    return provider_->leaudio_broadcast_volume_control_for_connected_devices();
}
inline bool leaudio_check_ecosystem_base_interval_support() {
    return provider_->leaudio_check_ecosystem_base_interval_support();
}
inline bool leaudio_config_profile_enabling() {
    return provider_->leaudio_config_profile_enabling();
}
inline bool leaudio_connection_subrating() {
    return provider_->leaudio_connection_subrating();
}
inline bool leaudio_dev_options_respect_profile_sysprops() {
    return provider_->leaudio_dev_options_respect_profile_sysprops();
}
inline bool leaudio_disable_broadcast_for_hap_device() {
    return provider_->leaudio_disable_broadcast_for_hap_device();
}
inline bool leaudio_do_not_set_autoconnecting_on_connected_device() {
    return provider_->leaudio_do_not_set_autoconnecting_on_connected_device();
}
inline bool leaudio_dynamic_data_path_change() {
    return provider_->leaudio_dynamic_data_path_change();
}
inline bool leaudio_dynamic_direction_opening() {
    return provider_->leaudio_dynamic_direction_opening();
}
inline bool leaudio_fix_stop_reconfiguration_timeout() {
    return provider_->leaudio_fix_stop_reconfiguration_timeout();
}
inline bool leaudio_improve_switching_le_audio_devices() {
    return provider_->leaudio_improve_switching_le_audio_devices();
}
inline bool leaudio_intent_broadcast_in_state_machine_cleanup() {
    return provider_->leaudio_intent_broadcast_in_state_machine_cleanup();
}
inline bool leaudio_mono_location_errata_api() {
    return provider_->leaudio_mono_location_errata_api();
}
inline bool leaudio_multiple_vocs_instances_api() {
    return provider_->leaudio_multiple_vocs_instances_api();
}
inline bool leaudio_peripheral_feature() {
    return provider_->leaudio_peripheral_feature();
}
inline bool leaudio_set_codec_config_preference() {
    return provider_->leaudio_set_codec_config_preference();
}
inline bool leaudio_use_aggressive_params() {
    return provider_->leaudio_use_aggressive_params();
}
inline bool leaudio_use_context_type_manager() {
    return provider_->leaudio_use_context_type_manager();
}
inline bool leaudio_use_game_sonification_as_regular_sonification() {
    return provider_->leaudio_use_game_sonification_as_regular_sonification();
}
inline bool lhdc_codec_support() {
    return provider_->lhdc_codec_support();
}
inline bool link_status_api() {
    return provider_->link_status_api();
}
inline bool maintain_call_index_after_conference() {
    return provider_->maintain_call_index_after_conference();
}
inline bool make_socket_read_behavior_consistent() {
    return provider_->make_socket_read_behavior_consistent();
}
inline bool map_client_check_access_permission() {
    return provider_->map_client_check_access_permission();
}
inline bool map_continue_operation() {
    return provider_->map_continue_operation();
}
inline bool map_mime_multipart() {
    return provider_->map_mime_multipart();
}
inline bool merge_call_with_held_conference() {
    return provider_->merge_call_with_held_conference();
}
inline bool metadata_api_inactive_audio_device_upon_connection() {
    return provider_->metadata_api_inactive_audio_device_upon_connection();
}
inline bool metadata_api_microphone_for_call_enabled() {
    return provider_->metadata_api_microphone_for_call_enabled();
}
inline bool microphone_mute_status_sync() {
    return provider_->microphone_mute_status_sync();
}
inline bool mode_change_before_sco_unpark() {
    return provider_->mode_change_before_sco_unpark();
}
inline bool monitor_read_flag_on_offloaded_socket() {
    return provider_->monitor_read_flag_on_offloaded_socket();
}
inline bool msft_addr_tracking_quirk() {
    return provider_->msft_addr_tracking_quirk();
}
inline bool non_bonded_device_properties() {
    return provider_->non_bonded_device_properties();
}
inline bool non_conference_call_hangup() {
    return provider_->non_conference_call_hangup();
}
inline bool non_zero_local_irk() {
    return provider_->non_zero_local_irk();
}
inline bool not_delete_locked_message() {
    return provider_->not_delete_locked_message();
}
inline bool nrpa_non_connectable_adv() {
    return provider_->nrpa_non_connectable_adv();
}
inline bool on_to_ble_on_via_off() {
    return provider_->on_to_ble_on_via_off();
}
inline bool only_broadcast_to_local_user() {
    return provider_->only_broadcast_to_local_user();
}
inline bool only_start_scan_during_ble_on() {
    return provider_->only_start_scan_during_ble_on();
}
inline bool opp_check_content_uri_permissions() {
    return provider_->opp_check_content_uri_permissions();
}
inline bool opp_device_picker_extra_intent_apis() {
    return provider_->opp_device_picker_extra_intent_apis();
}
inline bool original_address_filter_match() {
    return provider_->original_address_filter_match();
}
inline bool pairing_collision_with_same_device() {
    return provider_->pairing_collision_with_same_device();
}
inline bool pbap_cleanup_use_handler() {
    return provider_->pbap_cleanup_use_handler();
}
inline bool pbap_client_check_access_permission() {
    return provider_->pbap_client_check_access_permission();
}
inline bool pbap_client_contacts_caching() {
    return provider_->pbap_client_contacts_caching();
}
inline bool pbap_limit_call_log() {
    return provider_->pbap_limit_call_log();
}
inline bool preload_gatt_database() {
    return provider_->preload_gatt_database();
}
inline bool prevent_adding_both_pseudo_and_identity_addr() {
    return provider_->prevent_adding_both_pseudo_and_identity_addr();
}
inline bool prevent_storage_access_without_gd_running() {
    return provider_->prevent_storage_access_without_gd_running();
}
inline bool prioritized_in_ear_routing() {
    return provider_->prioritized_in_ear_routing();
}
inline bool protect_dumpsys_during_stack_shutdown() {
    return provider_->protect_dumpsys_during_stack_shutdown();
}
inline bool qc_aptx_codec_negotiation() {
    return provider_->qc_aptx_codec_negotiation();
}
inline bool qc_prioritize_lc3_codec() {
    return provider_->qc_prioritize_lc3_codec();
}
inline bool qc_send_error_at_bcc_ibr_disabled() {
    return provider_->qc_send_error_at_bcc_ibr_disabled();
}
inline bool queue_dis_requests() {
    return provider_->queue_dis_requests();
}
inline bool read_ppcp_only_for_success() {
    return provider_->read_ppcp_only_for_success();
}
inline bool read_rssi_throttling() {
    return provider_->read_rssi_throttling();
}
inline bool reboke_permission_on_unbond() {
    return provider_->reboke_permission_on_unbond();
}
inline bool reconnect_on_hogp_connection_failure() {
    return provider_->reconnect_on_hogp_connection_failure();
}
inline bool ref_counted_native_wakelock() {
    return provider_->ref_counted_native_wakelock();
}
inline bool refactor_saving_messages_and_metadata() {
    return provider_->refactor_saving_messages_and_metadata();
}
inline bool reject_bond_request_during_bonding() {
    return provider_->reject_bond_request_during_bonding();
}
inline bool release_port_in_bta_ag_rfc_fail_before_reset_context() {
    return provider_->release_port_in_bta_ag_rfc_fail_before_reset_context();
}
inline bool remove_address_cache_from_ble_scanner() {
    return provider_->remove_address_cache_from_ble_scanner();
}
inline bool remove_device_with_connection_manager() {
    return provider_->remove_device_with_connection_manager();
}
inline bool remove_handler_clear() {
    return provider_->remove_handler_clear();
}
inline bool remove_hop_from_le_adv_set_term() {
    return provider_->remove_hop_from_le_adv_set_term();
}
inline bool replace_message_loop_thread_with_gd_handler() {
    return provider_->replace_message_loop_thread_with_gd_handler();
}
inline bool reset_collision_state_on_encryption() {
    return provider_->reset_collision_state_on_encryption();
}
inline bool reset_security_flags_on_pairing_failure() {
    return provider_->reset_security_flags_on_pairing_failure();
}
inline bool reset_service_change_ind_counter() {
    return provider_->reset_service_change_ind_counter();
}
inline bool reset_state_when_removing_non_connected_hid_device() {
    return provider_->reset_state_when_removing_non_connected_hid_device();
}
inline bool resolve_address_for_adv_report() {
    return provider_->resolve_address_for_adv_report();
}
inline bool retain_address_type() {
    return provider_->retain_address_type();
}
inline bool return_correct_ble_state() {
    return provider_->return_correct_ble_state();
}
inline bool rfcomm_fix_bta_ag_rfc_acp_open_error() {
    return provider_->rfcomm_fix_bta_ag_rfc_acp_open_error();
}
inline bool rfcomm_fix_mux_collision_handling() {
    return provider_->rfcomm_fix_mux_collision_handling();
}
inline bool rnr_directly_call_gap_over_le() {
    return provider_->rnr_directly_call_gap_over_le();
}
inline bool rnr_validate_page_scan_repetition_mode() {
    return provider_->rnr_validate_page_scan_repetition_mode();
}
inline bool role_switch_after_encryption() {
    return provider_->role_switch_after_encryption();
}
inline bool rssi_scan_filter() {
    return provider_->rssi_scan_filter();
}
inline bool same_handler_for_all_modules() {
    return provider_->same_handler_for_all_modules();
}
inline bool save_cache_for_bonded_device() {
    return provider_->save_cache_for_bonded_device();
}
inline bool scan_controller_thread() {
    return provider_->scan_controller_thread();
}
inline bool sco_managed_by_audio_remove_hfp_hal() {
    return provider_->sco_managed_by_audio_remove_hfp_hal();
}
inline bool sco_state_machine_cleanup() {
    return provider_->sco_state_machine_cleanup();
}
inline bool sco_state_machine_update_in_codec_state() {
    return provider_->sco_state_machine_update_in_codec_state();
}
inline bool sdp_reset_transport_status_if_disconnect() {
    return provider_->sdp_reset_transport_status_if_disconnect();
}
inline bool send_ok_clcc_before_slc() {
    return provider_->send_ok_clcc_before_slc();
}
inline bool send_ok_on_no_action_on_chld() {
    return provider_->send_ok_on_no_action_on_chld();
}
inline bool send_opp_device_picker_extra_intent() {
    return provider_->send_opp_device_picker_extra_intent();
}
inline bool separate_encryption_queue() {
    return provider_->separate_encryption_queue();
}
inline bool service_discovery_on_connected_transport() {
    return provider_->service_discovery_on_connected_transport();
}
inline bool service_rediscovery_fix() {
    return provider_->service_rediscovery_fix();
}
inline bool set_a2dp_active_device_through_adapter_service() {
    return provider_->set_a2dp_active_device_through_adapter_service();
}
inline bool set_component_available_fix() {
    return provider_->set_component_available_fix();
}
inline bool set_max_data_length_for_lecoc() {
    return provider_->set_max_data_length_for_lecoc();
}
inline bool set_ptr_null_after_free() {
    return provider_->set_ptr_null_after_free();
}
inline bool settings_can_control_hap_preset() {
    return provider_->settings_can_control_hap_preset();
}
inline bool shutdown_main_thread_before_cleanup() {
    return provider_->shutdown_main_thread_before_cleanup();
}
inline bool simpler_hid_connection_policy() {
    return provider_->simpler_hid_connection_policy();
}
inline bool skip_excess_name_discovery() {
    return provider_->skip_excess_name_discovery();
}
inline bool skip_unknown_robust_caching() {
    return provider_->skip_unknown_robust_caching();
}
inline bool smp_connection_status_handling_when_no_acl() {
    return provider_->smp_connection_status_handling_when_no_acl();
}
inline bool sniff_offload_with_vsc_based_control() {
    return provider_->sniff_offload_with_vsc_based_control();
}
inline bool snoop_logger_save_multiple_snoop_logs() {
    return provider_->snoop_logger_save_multiple_snoop_logs();
}
inline bool socket_settings_api() {
    return provider_->socket_settings_api();
}
inline bool stack_sdp_detect_nil_property_type() {
    return provider_->stack_sdp_detect_nil_property_type();
}
inline bool start_discover_service_changed() {
    return provider_->start_discover_service_changed();
}
inline bool start_leaudio_subrate_for_active_set_only() {
    return provider_->start_leaudio_subrate_for_active_set_only();
}
inline bool stop_le_scan_system_suspend() {
    return provider_->stop_le_scan_system_suspend();
}
inline bool support_bluetooth_quality_report_v6() {
    return provider_->support_bluetooth_quality_report_v6();
}
inline bool support_metadata_device_types_apis() {
    return provider_->support_metadata_device_types_apis();
}
inline bool support_passive_scanning() {
    return provider_->support_passive_scanning();
}
inline bool support_zoomed_in_icon_metadata() {
    return provider_->support_zoomed_in_icon_metadata();
}
inline bool synchronize_codec_preferences_and_priority() {
    return provider_->synchronize_codec_preferences_and_priority();
}
inline bool synchronize_preset_can_timeout() {
    return provider_->synchronize_preset_can_timeout();
}
inline bool system_server_messenger() {
    return provider_->system_server_messenger();
}
inline bool tbs_gatt_no_longer_calls_framework() {
    return provider_->tbs_gatt_no_longer_calls_framework();
}
inline bool tbs_set_lea_from_btservice() {
    return provider_->tbs_set_lea_from_btservice();
}
inline bool temporary_pairing_tracking() {
    return provider_->temporary_pairing_tracking();
}
inline bool trigger_sec_proc_on_inc_access_req() {
    return provider_->trigger_sec_proc_on_inc_access_req();
}
inline bool unix_file_socket_creation_failure() {
    return provider_->unix_file_socket_creation_failure();
}
inline bool unrelated_device_smp_cancellation() {
    return provider_->unrelated_device_smp_cancellation();
}
inline bool update_cod_if_missing() {
    return provider_->update_cod_if_missing();
}
inline bool upgrade_le_scan_only_screen_on() {
    return provider_->upgrade_le_scan_only_screen_on();
}
inline bool upgrade_temp_bonding_on_auth_req() {
    return provider_->upgrade_temp_bonding_on_auth_req();
}
inline bool use_data_store_storage() {
    return provider_->use_data_store_storage();
}
inline bool use_entire_message_handle() {
    return provider_->use_entire_message_handle();
}
inline bool use_returned_absolute_volume() {
    return provider_->use_returned_absolute_volume();
}
inline bool use_shared_promise_for_le_address_manager() {
    return provider_->use_shared_promise_for_le_address_manager();
}
inline bool user_restriction_refactor() {
    return provider_->user_restriction_refactor();
}
inline bool user_visible_on_user_starting() {
    return provider_->user_visible_on_user_starting();
}
inline bool validate_connection_policy_before_accepting_connection() {
    return provider_->validate_connection_policy_before_accepting_connection();
}
inline bool vcp_handle_group_id_internally() {
    return provider_->vcp_handle_group_id_internally();
}
inline bool vcp_on_main_looper() {
    return provider_->vcp_on_main_looper();
}
inline bool voice_recognition_fixes() {
    return provider_->voice_recognition_fixes();
}
inline bool wait_hid_disconnect_before_marking_unused() {
    return provider_->wait_hid_disconnect_before_marking_unused();
}
inline bool watch_device_override_airplane_mode() {
    return provider_->watch_device_override_airplane_mode();
}

}

extern "C" {
#endif // __cplusplus


bool com_android_bluetooth_flags_a2dp_adjust_sbc_bitpool();
bool com_android_bluetooth_flags_a2dp_cancel_acceptor_alarm_for_avdt_init();
bool com_android_bluetooth_flags_a2dp_delay_disconnect();
bool com_android_bluetooth_flags_a2dp_delay_report_in_dumpsys();
bool com_android_bluetooth_flags_a2dp_disconnect_reason_api();
bool com_android_bluetooth_flags_a2dp_fmq_read_exact();
bool com_android_bluetooth_flags_a2dp_lhdc_api();
bool com_android_bluetooth_flags_a2dp_pm_app_id();
bool com_android_bluetooth_flags_a2dp_reject_sho_request();
bool com_android_bluetooth_flags_a2dp_sbc_underflow_recovery();
bool com_android_bluetooth_flags_a2dp_set_configuration_during_discovery();
bool com_android_bluetooth_flags_a2dp_source_null_fixed_queue();
bool com_android_bluetooth_flags_abs_volume_sdp_conflict();
bool com_android_bluetooth_flags_acl_fix_in_and_out_connection_reqs();
bool com_android_bluetooth_flags_adapter_suspend_advertisement();
bool com_android_bluetooth_flags_adapter_suspend_discoverability();
bool com_android_bluetooth_flags_adapter_suspend_mgmt();
bool com_android_bluetooth_flags_add_bond_loss_reason();
bool com_android_bluetooth_flags_add_hop_to_event_callback();
bool com_android_bluetooth_flags_add_profile_as_intent_extra();
bool com_android_bluetooth_flags_adm_centralize_active_device_handling();
bool com_android_bluetooth_flags_adm_remove_handling_wired();
bool com_android_bluetooth_flags_adm_unset_others_on_hfp_changed();
bool com_android_bluetooth_flags_aics_api();
bool com_android_bluetooth_flags_allow_rearm_if_suspend_scan_params_used();
bool com_android_bluetooth_flags_allow_switching_hid_and_hogp();
bool com_android_bluetooth_flags_always_set_identity_addr();
bool com_android_bluetooth_flags_asha_omit_gatt_after_svc_changed();
bool com_android_bluetooth_flags_avdt_close_on_start_failure_bad_state();
bool com_android_bluetooth_flags_avdt_wait_for_initial_delay_report_as_initiator();
bool com_android_bluetooth_flags_avoid_ctkd_for_temp_pairing();
bool com_android_bluetooth_flags_avoid_l2c_processing_while_stack_shutdown();
bool com_android_bluetooth_flags_avrcp_16_default();
bool com_android_bluetooth_flags_batch_scan_support_check();
bool com_android_bluetooth_flags_ble_rnr_when_connected();
bool com_android_bluetooth_flags_bluetooth_power_telemetry();
bool com_android_bluetooth_flags_bond_loss_transport_check();
bool com_android_bluetooth_flags_bond_state_machine_looper();
bool com_android_bluetooth_flags_bonding_initiator_state_reset();
bool com_android_bluetooth_flags_bqr_common_part_unified_length();
bool com_android_bluetooth_flags_br_edr_discover_gatt_services_over_gatt();
bool com_android_bluetooth_flags_broadcast_transport_type_on_reset();
bool com_android_bluetooth_flags_bt_offload_socket_api();
bool com_android_bluetooth_flags_bt_socket_api_l2cap_cid();
bool com_android_bluetooth_flags_btsec_check_controller_sc_support();
bool com_android_bluetooth_flags_btsec_cycle_irks();
bool com_android_bluetooth_flags_call_sdp_free_in_main_thread();
bool com_android_bluetooth_flags_channel_sounding();
bool com_android_bluetooth_flags_channel_sounding_25q2_apis();
bool com_android_bluetooth_flags_channel_sounding_offload();
bool com_android_bluetooth_flags_check_call_state_atd();
bool com_android_bluetooth_flags_check_l2c_conn_status_before_param_validation();
bool com_android_bluetooth_flags_check_peer_hf_indicator();
bool com_android_bluetooth_flags_clear_pairing_state_when_no_devrec();
bool com_android_bluetooth_flags_complete_disc_if_no_rnr();
bool com_android_bluetooth_flags_conclude_le_pairing_immediately();
bool com_android_bluetooth_flags_concurrent_incoming_outgoing_pairing();
bool com_android_bluetooth_flags_consider_l2c_header_bytes_for_mps_selection();
bool com_android_bluetooth_flags_consistent_battery_level();
bool com_android_bluetooth_flags_continue_queued_command_after_discovery();
bool com_android_bluetooth_flags_delay_jv_pm_idle();
bool com_android_bluetooth_flags_delay_offload_le_coc_connection_ind();
bool com_android_bluetooth_flags_delay_sniff_subrating();
bool com_android_bluetooth_flags_directed_advertising_api();
bool com_android_bluetooth_flags_disconnect_acl_on_gatt_timeout();
bool com_android_bluetooth_flags_disconnect_acls_by_bredr_disabled();
bool com_android_bluetooth_flags_distance_measurement_thread();
bool com_android_bluetooth_flags_do_not_dump_devices_from_adapter_properties();
bool com_android_bluetooth_flags_do_not_hardcode_tmap_role_mask();
bool com_android_bluetooth_flags_donot_collide_with_closed_port();
bool com_android_bluetooth_flags_donot_mandate_auth_along_with_encryption();
bool com_android_bluetooth_flags_donot_pm_classic_on_le_traffic();
bool com_android_bluetooth_flags_dont_send_hci_disconnect_repeatedly();
bool com_android_bluetooth_flags_downgrade_to_basic_mode_on_no_info_resp();
bool com_android_bluetooth_flags_dsa_use_codec_extensibility();
bool com_android_bluetooth_flags_dump_without_promise_timeout();
bool com_android_bluetooth_flags_early_incoming_hid_connection();
bool com_android_bluetooth_flags_enable_battery_level_update_only_through_hf_indicator();
bool com_android_bluetooth_flags_encryption_change_broadcast();
bool com_android_bluetooth_flags_end_outgoing_call_on_chld();
bool com_android_bluetooth_flags_ensure_acl_connection_is_removed_from_pending_list();
bool com_android_bluetooth_flags_extend_and_randomize_role_switch_delay();
bool com_android_bluetooth_flags_fix_buf_len_check_for_first_k_frame();
bool com_android_bluetooth_flags_fix_event_handler_reg_and_dereg();
bool com_android_bluetooth_flags_fix_hfp_qual_1_9();
bool com_android_bluetooth_flags_fix_hfp_rfcomm_collision_state_machine_error();
bool com_android_bluetooth_flags_fix_lecoc_socket_available();
bool com_android_bluetooth_flags_fix_ongoing_rnr_while_bonding();
bool com_android_bluetooth_flags_fix_private_gatt_advertisement();
bool com_android_bluetooth_flags_fix_race_in_orphaned_acls();
bool com_android_bluetooth_flags_fix_socket_connection_failed_no_callback();
bool com_android_bluetooth_flags_fix_started_module_race();
bool com_android_bluetooth_flags_fix_unhandled_bqr_subevent();
bool com_android_bluetooth_flags_fix_use_after_object_destroyed();
bool com_android_bluetooth_flags_flag_handle_hci_error_controller_busy();
bool com_android_bluetooth_flags_floss_separate_host_privacy_and_llprivacy();
bool com_android_bluetooth_flags_gatt_clear_cache_on_factory_reset();
bool com_android_bluetooth_flags_gatt_discovery_is_non_opportunistic_client();
bool com_android_bluetooth_flags_gatt_failure_callback_on_cancel();
bool com_android_bluetooth_flags_gatt_messaging_permissions();
bool com_android_bluetooth_flags_gatt_multi_bearer_connections();
bool com_android_bluetooth_flags_gatt_multi_bearer_transactions();
bool com_android_bluetooth_flags_gatt_offload_api();
bool com_android_bluetooth_flags_gen_key_missing_evt_only_from_iocapreq();
bool com_android_bluetooth_flags_get_all_element_attributes_empty();
bool com_android_bluetooth_flags_get_profile_oneway();
bool com_android_bluetooth_flags_get_svc_uuids_bugfix();
bool com_android_bluetooth_flags_get_svc_uuids_from_ble_adv_data();
bool com_android_bluetooth_flags_graceful_disable_without_message();
bool com_android_bluetooth_flags_handle_delivery_sending_failure_events();
bool com_android_bluetooth_flags_handle_encryption_fail_before_sdp_when_paring();
bool com_android_bluetooth_flags_hap_on_main_looper();
bool com_android_bluetooth_flags_hap_safely_erase_pending_operation_timeout();
bool com_android_bluetooth_flags_hci_instance_name_use_injected();
bool com_android_bluetooth_flags_hci_vendor_specific_extension();
bool com_android_bluetooth_flags_hfp_client_disconnecting_state();
bool com_android_bluetooth_flags_hfp_sco_state_reset_when_profile_restart();
bool com_android_bluetooth_flags_hh_state_update_race_fix();
bool com_android_bluetooth_flags_hid_connection_timeout_in_jni_thread();
bool com_android_bluetooth_flags_hidd_handle_set_protocol_before_interrupt_connected();
bool com_android_bluetooth_flags_hidh_close_in_jni_thread();
bool com_android_bluetooth_flags_hogp_direct_connection_upgrade();
bool com_android_bluetooth_flags_hogp_encryption_collision();
bool com_android_bluetooth_flags_hold_conference_call_from_remote();
bool com_android_bluetooth_flags_idempotent_direct_connect_add();
bool com_android_bluetooth_flags_identity_address_type_api();
bool com_android_bluetooth_flags_identity_to_pseudo_addr();
bool com_android_bluetooth_flags_ignore_auth_req_when_collision_timer_active();
bool com_android_bluetooth_flags_ignore_le_smp_conn_when_sm_over_br_progress();
bool com_android_bluetooth_flags_ignore_message_sms_disallowed();
bool com_android_bluetooth_flags_ignore_multiple_connect_request_in_bt_services();
bool com_android_bluetooth_flags_ignore_unrelated_cancel_bond();
bool com_android_bluetooth_flags_immediate_encryption_after_pairing();
bool com_android_bluetooth_flags_implement_get_image_from_descriptor_for_cover_art();
bool com_android_bluetooth_flags_increase_contact_image_resolution();
bool com_android_bluetooth_flags_indicate_rfcomm_connection_complete_after_msc();
bool com_android_bluetooth_flags_initial_conn_params_p1();
bool com_android_bluetooth_flags_invalidate_hci_handle_on_acl_removal();
bool com_android_bluetooth_flags_irk_scan_bond_check_update();
bool com_android_bluetooth_flags_key_missing_count_api();
bool com_android_bluetooth_flags_key_missing_public();
bool com_android_bluetooth_flags_l2c_not_cancel_timeout();
bool com_android_bluetooth_flags_l2cap_improve_segmented_sdu();
bool com_android_bluetooth_flags_ldac_rate_control();
bool com_android_bluetooth_flags_le_address_map_update();
bool com_android_bluetooth_flags_le_ase_read_multiple_variable();
bool com_android_bluetooth_flags_le_audio_update_config_preference_to_hal();
bool com_android_bluetooth_flags_le_scan_msft_support();
bool com_android_bluetooth_flags_le_subrate_api();
bool com_android_bluetooth_flags_le_subrate_manager();
bool com_android_bluetooth_flags_leaudio_add_opus_codec_type();
bool com_android_bluetooth_flags_leaudio_add_opus_hi_res_codec_type();
bool com_android_bluetooth_flags_leaudio_add_opus_hi_res_codec_type_api();
bool com_android_bluetooth_flags_leaudio_bis_sync_control();
bool com_android_bluetooth_flags_leaudio_broadcast_allow_monitoring_on_resume();
bool com_android_bluetooth_flags_leaudio_broadcast_api_get_local_metadata();
bool com_android_bluetooth_flags_leaudio_broadcast_api_manage_primary_group();
bool com_android_bluetooth_flags_leaudio_broadcast_config_data_path_before_set_iso_data_path();
bool com_android_bluetooth_flags_leaudio_broadcast_fix_autonomous_source_adding();
bool com_android_bluetooth_flags_leaudio_broadcast_monitor_source_sync_status();
bool com_android_bluetooth_flags_leaudio_broadcast_remove_sink_metadata_on_switch_to_local();
bool com_android_bluetooth_flags_leaudio_broadcast_simplify_set_bcast_code();
bool com_android_bluetooth_flags_leaudio_broadcast_source_channel_map_classification();
bool com_android_bluetooth_flags_leaudio_broadcast_volume_control_for_connected_devices();
bool com_android_bluetooth_flags_leaudio_check_ecosystem_base_interval_support();
bool com_android_bluetooth_flags_leaudio_config_profile_enabling();
bool com_android_bluetooth_flags_leaudio_connection_subrating();
bool com_android_bluetooth_flags_leaudio_dev_options_respect_profile_sysprops();
bool com_android_bluetooth_flags_leaudio_disable_broadcast_for_hap_device();
bool com_android_bluetooth_flags_leaudio_do_not_set_autoconnecting_on_connected_device();
bool com_android_bluetooth_flags_leaudio_dynamic_data_path_change();
bool com_android_bluetooth_flags_leaudio_dynamic_direction_opening();
bool com_android_bluetooth_flags_leaudio_fix_stop_reconfiguration_timeout();
bool com_android_bluetooth_flags_leaudio_improve_switching_le_audio_devices();
bool com_android_bluetooth_flags_leaudio_intent_broadcast_in_state_machine_cleanup();
bool com_android_bluetooth_flags_leaudio_mono_location_errata_api();
bool com_android_bluetooth_flags_leaudio_multiple_vocs_instances_api();
bool com_android_bluetooth_flags_leaudio_peripheral_feature();
bool com_android_bluetooth_flags_leaudio_set_codec_config_preference();
bool com_android_bluetooth_flags_leaudio_use_aggressive_params();
bool com_android_bluetooth_flags_leaudio_use_context_type_manager();
bool com_android_bluetooth_flags_leaudio_use_game_sonification_as_regular_sonification();
bool com_android_bluetooth_flags_lhdc_codec_support();
bool com_android_bluetooth_flags_link_status_api();
bool com_android_bluetooth_flags_maintain_call_index_after_conference();
bool com_android_bluetooth_flags_make_socket_read_behavior_consistent();
bool com_android_bluetooth_flags_map_client_check_access_permission();
bool com_android_bluetooth_flags_map_continue_operation();
bool com_android_bluetooth_flags_map_mime_multipart();
bool com_android_bluetooth_flags_merge_call_with_held_conference();
bool com_android_bluetooth_flags_metadata_api_inactive_audio_device_upon_connection();
bool com_android_bluetooth_flags_metadata_api_microphone_for_call_enabled();
bool com_android_bluetooth_flags_microphone_mute_status_sync();
bool com_android_bluetooth_flags_mode_change_before_sco_unpark();
bool com_android_bluetooth_flags_monitor_read_flag_on_offloaded_socket();
bool com_android_bluetooth_flags_msft_addr_tracking_quirk();
bool com_android_bluetooth_flags_non_bonded_device_properties();
bool com_android_bluetooth_flags_non_conference_call_hangup();
bool com_android_bluetooth_flags_non_zero_local_irk();
bool com_android_bluetooth_flags_not_delete_locked_message();
bool com_android_bluetooth_flags_nrpa_non_connectable_adv();
bool com_android_bluetooth_flags_on_to_ble_on_via_off();
bool com_android_bluetooth_flags_only_broadcast_to_local_user();
bool com_android_bluetooth_flags_only_start_scan_during_ble_on();
bool com_android_bluetooth_flags_opp_check_content_uri_permissions();
bool com_android_bluetooth_flags_opp_device_picker_extra_intent_apis();
bool com_android_bluetooth_flags_original_address_filter_match();
bool com_android_bluetooth_flags_pairing_collision_with_same_device();
bool com_android_bluetooth_flags_pbap_cleanup_use_handler();
bool com_android_bluetooth_flags_pbap_client_check_access_permission();
bool com_android_bluetooth_flags_pbap_client_contacts_caching();
bool com_android_bluetooth_flags_pbap_limit_call_log();
bool com_android_bluetooth_flags_preload_gatt_database();
bool com_android_bluetooth_flags_prevent_adding_both_pseudo_and_identity_addr();
bool com_android_bluetooth_flags_prevent_storage_access_without_gd_running();
bool com_android_bluetooth_flags_prioritized_in_ear_routing();
bool com_android_bluetooth_flags_protect_dumpsys_during_stack_shutdown();
bool com_android_bluetooth_flags_qc_aptx_codec_negotiation();
bool com_android_bluetooth_flags_qc_prioritize_lc3_codec();
bool com_android_bluetooth_flags_qc_send_error_at_bcc_ibr_disabled();
bool com_android_bluetooth_flags_queue_dis_requests();
bool com_android_bluetooth_flags_read_ppcp_only_for_success();
bool com_android_bluetooth_flags_read_rssi_throttling();
bool com_android_bluetooth_flags_reboke_permission_on_unbond();
bool com_android_bluetooth_flags_reconnect_on_hogp_connection_failure();
bool com_android_bluetooth_flags_ref_counted_native_wakelock();
bool com_android_bluetooth_flags_refactor_saving_messages_and_metadata();
bool com_android_bluetooth_flags_reject_bond_request_during_bonding();
bool com_android_bluetooth_flags_release_port_in_bta_ag_rfc_fail_before_reset_context();
bool com_android_bluetooth_flags_remove_address_cache_from_ble_scanner();
bool com_android_bluetooth_flags_remove_device_with_connection_manager();
bool com_android_bluetooth_flags_remove_handler_clear();
bool com_android_bluetooth_flags_remove_hop_from_le_adv_set_term();
bool com_android_bluetooth_flags_replace_message_loop_thread_with_gd_handler();
bool com_android_bluetooth_flags_reset_collision_state_on_encryption();
bool com_android_bluetooth_flags_reset_security_flags_on_pairing_failure();
bool com_android_bluetooth_flags_reset_service_change_ind_counter();
bool com_android_bluetooth_flags_reset_state_when_removing_non_connected_hid_device();
bool com_android_bluetooth_flags_resolve_address_for_adv_report();
bool com_android_bluetooth_flags_retain_address_type();
bool com_android_bluetooth_flags_return_correct_ble_state();
bool com_android_bluetooth_flags_rfcomm_fix_bta_ag_rfc_acp_open_error();
bool com_android_bluetooth_flags_rfcomm_fix_mux_collision_handling();
bool com_android_bluetooth_flags_rnr_directly_call_gap_over_le();
bool com_android_bluetooth_flags_rnr_validate_page_scan_repetition_mode();
bool com_android_bluetooth_flags_role_switch_after_encryption();
bool com_android_bluetooth_flags_rssi_scan_filter();
bool com_android_bluetooth_flags_same_handler_for_all_modules();
bool com_android_bluetooth_flags_save_cache_for_bonded_device();
bool com_android_bluetooth_flags_scan_controller_thread();
bool com_android_bluetooth_flags_sco_managed_by_audio_remove_hfp_hal();
bool com_android_bluetooth_flags_sco_state_machine_cleanup();
bool com_android_bluetooth_flags_sco_state_machine_update_in_codec_state();
bool com_android_bluetooth_flags_sdp_reset_transport_status_if_disconnect();
bool com_android_bluetooth_flags_send_ok_clcc_before_slc();
bool com_android_bluetooth_flags_send_ok_on_no_action_on_chld();
bool com_android_bluetooth_flags_send_opp_device_picker_extra_intent();
bool com_android_bluetooth_flags_separate_encryption_queue();
bool com_android_bluetooth_flags_service_discovery_on_connected_transport();
bool com_android_bluetooth_flags_service_rediscovery_fix();
bool com_android_bluetooth_flags_set_a2dp_active_device_through_adapter_service();
bool com_android_bluetooth_flags_set_component_available_fix();
bool com_android_bluetooth_flags_set_max_data_length_for_lecoc();
bool com_android_bluetooth_flags_set_ptr_null_after_free();
bool com_android_bluetooth_flags_settings_can_control_hap_preset();
bool com_android_bluetooth_flags_shutdown_main_thread_before_cleanup();
bool com_android_bluetooth_flags_simpler_hid_connection_policy();
bool com_android_bluetooth_flags_skip_excess_name_discovery();
bool com_android_bluetooth_flags_skip_unknown_robust_caching();
bool com_android_bluetooth_flags_smp_connection_status_handling_when_no_acl();
bool com_android_bluetooth_flags_sniff_offload_with_vsc_based_control();
bool com_android_bluetooth_flags_snoop_logger_save_multiple_snoop_logs();
bool com_android_bluetooth_flags_socket_settings_api();
bool com_android_bluetooth_flags_stack_sdp_detect_nil_property_type();
bool com_android_bluetooth_flags_start_discover_service_changed();
bool com_android_bluetooth_flags_start_leaudio_subrate_for_active_set_only();
bool com_android_bluetooth_flags_stop_le_scan_system_suspend();
bool com_android_bluetooth_flags_support_bluetooth_quality_report_v6();
bool com_android_bluetooth_flags_support_metadata_device_types_apis();
bool com_android_bluetooth_flags_support_passive_scanning();
bool com_android_bluetooth_flags_support_zoomed_in_icon_metadata();
bool com_android_bluetooth_flags_synchronize_codec_preferences_and_priority();
bool com_android_bluetooth_flags_synchronize_preset_can_timeout();
bool com_android_bluetooth_flags_system_server_messenger();
bool com_android_bluetooth_flags_tbs_gatt_no_longer_calls_framework();
bool com_android_bluetooth_flags_tbs_set_lea_from_btservice();
bool com_android_bluetooth_flags_temporary_pairing_tracking();
bool com_android_bluetooth_flags_trigger_sec_proc_on_inc_access_req();
bool com_android_bluetooth_flags_unix_file_socket_creation_failure();
bool com_android_bluetooth_flags_unrelated_device_smp_cancellation();
bool com_android_bluetooth_flags_update_cod_if_missing();
bool com_android_bluetooth_flags_upgrade_le_scan_only_screen_on();
bool com_android_bluetooth_flags_upgrade_temp_bonding_on_auth_req();
bool com_android_bluetooth_flags_use_data_store_storage();
bool com_android_bluetooth_flags_use_entire_message_handle();
bool com_android_bluetooth_flags_use_returned_absolute_volume();
bool com_android_bluetooth_flags_use_shared_promise_for_le_address_manager();
bool com_android_bluetooth_flags_user_restriction_refactor();
bool com_android_bluetooth_flags_user_visible_on_user_starting();
bool com_android_bluetooth_flags_validate_connection_policy_before_accepting_connection();
bool com_android_bluetooth_flags_vcp_handle_group_id_internally();
bool com_android_bluetooth_flags_vcp_on_main_looper();
bool com_android_bluetooth_flags_voice_recognition_fixes();
bool com_android_bluetooth_flags_wait_hid_disconnect_before_marking_unused();
bool com_android_bluetooth_flags_watch_device_override_airplane_mode();

#ifdef __cplusplus
} // extern "C"
#endif

