#pragma once



#ifdef __cplusplus

#include <memory>

namespace com::android::bluetooth::flags {

class flag_provider_interface {
public:
    virtual ~flag_provider_interface() = default;
    virtual bool a2dp_async_allow_low_latency() = 0;
    virtual bool a2dp_concurrent_source_sink() = 0;
    virtual bool a2dp_ignore_started_when_responder() = 0;
    virtual bool a2dp_offload_codec_extensibility() = 0;
    virtual bool a2dp_service_looper() = 0;
    virtual bool abs_volume_sdp_conflict() = 0;
    virtual bool airplane_mode_x_ble_on() = 0;
    virtual bool allow_switching_hid_and_hogp() = 0;
    virtual bool android_headtracker_service() = 0;
    virtual bool api_get_connection_state_using_identity_address() = 0;
    virtual bool asha_asrc() = 0;
    virtual bool asymmetric_phy_for_unidirectional_cis() = 0;
    virtual bool audio_port_binder_inherit_rt() = 0;
    virtual bool audio_routing_centralization() = 0;
    virtual bool auto_connect_on_hfp_when_no_a2dp_device() = 0;
    virtual bool auto_connect_on_multiple_hfp_when_no_a2dp_device() = 0;
    virtual bool auto_on_feature() = 0;
    virtual bool avdtp_error_codes() = 0;
    virtual bool avoid_static_loading_of_native() = 0;
    virtual bool avrcp_connect_a2dp_delayed() = 0;
    virtual bool avrcp_sdp_records() = 0;
    virtual bool ble_check_data_length_on_legacy_advertising() = 0;
    virtual bool ble_context_map_remove_fix() = 0;
    virtual bool ble_gatt_server_use_address_type_in_connection() = 0;
    virtual bool ble_scan_adv_metrics_redesign() = 0;
    virtual bool bluetooth_power_telemetry() = 0;
    virtual bool bluffs_mitigation() = 0;
    virtual bool bond_transport_after_bond_cancel_fix() = 0;
    virtual bool break_uhid_polling_early() = 0;
    virtual bool browsing_refactor() = 0;
    virtual bool bt_socket_api_l2cap_cid() = 0;
    virtual bool bt_system_context_report() = 0;
    virtual bool bta_ag_cmd_brsf_allow_uint32() = 0;
    virtual bool bta_av_setconfig_rej_type_confusion() = 0;
    virtual bool bta_av_use_peer_codec() = 0;
    virtual bool bta_dm_defer_device_discovery_state_change_until_rnr_complete() = 0;
    virtual bool bta_dm_disc_stuck_in_cancelling_fix() = 0;
    virtual bool bta_dm_discover_both() = 0;
    virtual bool cancel_pairing_only_on_disconnected_transport() = 0;
    virtual bool channel_sounding() = 0;
    virtual bool channel_sounding_in_stack() = 0;
    virtual bool cleanup_le_only_device_type() = 0;
    virtual bool clear_collision_state_on_pairing_complete() = 0;
    virtual bool close_rfcomm_instead_of_reset() = 0;
    virtual bool connect_hid_after_service_discovery() = 0;
    virtual bool continue_service_discovery_when_cancel_device_discovery() = 0;
    virtual bool correct_bond_type_of_loaded_devices() = 0;
    virtual bool device_iot_config_logging() = 0;
    virtual bool divide_long_single_gap_data() = 0;
    virtual bool do_not_replace_existing_cod_with_uncategorized_cod() = 0;
    virtual bool dumpsys_acquire_stack_when_executing() = 0;
    virtual bool enable_hap_by_default() = 0;
    virtual bool enable_sniff_offload() = 0;
    virtual bool encrypted_advertising_data() = 0;
    virtual bool ensure_valid_adv_flag() = 0;
    virtual bool enumerate_gatt_errors() = 0;
    virtual bool explicit_kill_from_system_server() = 0;
    virtual bool fast_bind_to_app() = 0;
    virtual bool fix_hfp_qual_1_9() = 0;
    virtual bool fix_le_oob_pairing_bypass() = 0;
    virtual bool fix_le_pairing_passkey_entry_bypass() = 0;
    virtual bool fix_nonconnectable_scannable_advertisement() = 0;
    virtual bool fix_pairing_failure_reason_from_remote() = 0;
    virtual bool floss_separate_host_privacy_and_llprivacy() = 0;
    virtual bool force_bredr_for_sdp_retry() = 0;
    virtual bool gatt_cleanup_restricted_handles() = 0;
    virtual bool gatt_drop_acl_on_out_of_resources_fix() = 0;
    virtual bool gatt_fix_device_busy() = 0;
    virtual bool gatt_reconnect_on_bt_on_fix() = 0;
    virtual bool gatt_rediscover_on_canceled() = 0;
    virtual bool gdx_device_discovery() = 0;
    virtual bool gdx_service_discovery() = 0;
    virtual bool get_address_type_api() = 0;
    virtual bool handle_delivery_sending_failure_events() = 0;
    virtual bool headset_client_am_hf_volume_symmetric() = 0;
    virtual bool headtracker_codec_capability() = 0;
    virtual bool hfp_codec_aptx_voice() = 0;
    virtual bool hid_report_queuing() = 0;
    virtual bool higher_l2cap_flush_threshold() = 0;
    virtual bool identity_address_null_if_unknown() = 0;
    virtual bool ignore_bond_type_for_le() = 0;
    virtual bool is_sco_managed_by_audio() = 0;
    virtual bool keep_hfp_active_during_leaudio_handover() = 0;
    virtual bool keep_stopped_media_browser_service() = 0;
    virtual bool key_missing_as_ordered_broadcast() = 0;
    virtual bool key_missing_broadcast() = 0;
    virtual bool key_missing_classic_device() = 0;
    virtual bool kill_instead_of_exit() = 0;
    virtual bool l2cap_le_do_not_adjust_min_interval() = 0;
    virtual bool l2cap_p_ccb_check_rewrite() = 0;
    virtual bool l2cap_tx_complete_cb_info() = 0;
    virtual bool le_audio_base_ecosystem_interval() = 0;
    virtual bool le_audio_dev_type_detection_fix() = 0;
    virtual bool le_audio_support_unidirectional_voice_assistant() = 0;
    virtual bool le_periodic_scanning_reassembler() = 0;
    virtual bool le_scan_fix_remote_exception() = 0;
    virtual bool le_scan_use_address_type() = 0;
    virtual bool le_scan_use_uid_for_importance() = 0;
    virtual bool leaudio_active_device_manager_group_handling_fix() = 0;
    virtual bool leaudio_add_sampling_frequencies() = 0;
    virtual bool leaudio_allow_leaudio_only_devices() = 0;
    virtual bool leaudio_allowed_context_mask() = 0;
    virtual bool leaudio_api_synchronized_block_fix() = 0;
    virtual bool leaudio_big_depends_on_audio_state() = 0;
    virtual bool leaudio_broadcast_assistant_handle_command_statuses() = 0;
    virtual bool leaudio_broadcast_assistant_peripheral_entrustment() = 0;
    virtual bool leaudio_broadcast_audio_handover_policies() = 0;
    virtual bool leaudio_broadcast_destroy_after_timeout() = 0;
    virtual bool leaudio_broadcast_extract_periodic_scanner_from_state_machine() = 0;
    virtual bool leaudio_broadcast_feature_support() = 0;
    virtual bool leaudio_broadcast_monitor_source_sync_status() = 0;
    virtual bool leaudio_broadcast_stop_on_streaming_request() = 0;
    virtual bool leaudio_broadcast_volume_control_for_connected_devices() = 0;
    virtual bool leaudio_broadcast_volume_control_with_set_volume() = 0;
    virtual bool leaudio_callback_on_group_stream_status() = 0;
    virtual bool leaudio_codec_config_callback_order_fix() = 0;
    virtual bool leaudio_dynamic_spatial_audio() = 0;
    virtual bool leaudio_enable_health_based_actions() = 0;
    virtual bool leaudio_getting_active_state_support() = 0;
    virtual bool leaudio_hal_client_asrc() = 0;
    virtual bool leaudio_mcs_tbs_authorization_rebond_fix() = 0;
    virtual bool leaudio_mono_location_errata() = 0;
    virtual bool leaudio_multicodec_aidl_support() = 0;
    virtual bool leaudio_multiple_vocs_instances_api() = 0;
    virtual bool leaudio_no_context_validate_streaming_request() = 0;
    virtual bool leaudio_quick_leaudio_toggle_switch_fix() = 0;
    virtual bool leaudio_resume_active_after_hfp_handover() = 0;
    virtual bool leaudio_start_request_state_mutex_check() = 0;
    virtual bool leaudio_start_stream_race_fix() = 0;
    virtual bool leaudio_synchronize_start() = 0;
    virtual bool leaudio_unicast_inactivate_device_based_on_context() = 0;
    virtual bool leaudio_use_audio_mode_listener() = 0;
    virtual bool leaudio_volume_change_on_ringtone_fix() = 0;
    virtual bool load_did_config_from_sysprops() = 0;
    virtual bool map_limit_notification() = 0;
    virtual bool mcp_allow_play_without_active_player() = 0;
    virtual bool metadata_api_inactive_audio_device_upon_connection() = 0;
    virtual bool mfi_has_uuid() = 0;
    virtual bool msft_addr_tracking_quirk() = 0;
    virtual bool nrpa_non_connectable_adv() = 0;
    virtual bool opp_fix_multiple_notifications_issues() = 0;
    virtual bool opp_ignore_content_observer_after_service_stop() = 0;
    virtual bool opp_start_activity_directly_from_notification() = 0;
    virtual bool pairing_on_unknown_transport() = 0;
    virtual bool phy_to_native() = 0;
    virtual bool pretend_network_service() = 0;
    virtual bool prevent_hogp_reconnect_when_connected() = 0;
    virtual bool randomize_device_level_media_ids() = 0;
    virtual bool read_model_num_fix() = 0;
    virtual bool remove_address_map_on_unbond() = 0;
    virtual bool reset_after_collision() = 0;
    virtual bool reset_ag_state_on_collision() = 0;
    virtual bool reset_pairing_only_for_related_service_discovery() = 0;
    virtual bool respect_ble_scan_setting() = 0;
    virtual bool retry_esco_with_zero_retransmission_effort() = 0;
    virtual bool rfcomm_always_use_mitm() = 0;
    virtual bool rfcomm_bypass_post_to_main() = 0;
    virtual bool rnr_present_during_service_discovery() = 0;
    virtual bool rnr_reset_state_at_cancel() = 0;
    virtual bool rnr_store_device_type() = 0;
    virtual bool rnr_validate_page_scan_repetition_mode() = 0;
    virtual bool run_ble_audio_ticks_in_worker_thread() = 0;
    virtual bool run_clock_recovery_in_worker_thread() = 0;
    virtual bool save_initial_hid_connection_policy() = 0;
    virtual bool scan_manager_refactor() = 0;
    virtual bool scan_record_manufacturer_data_merge() = 0;
    virtual bool sec_dont_clear_keys_on_encryption_err() = 0;
    virtual bool separate_service_and_device_discovery() = 0;
    virtual bool settings_can_control_hap_preset() = 0;
    virtual bool sink_audio_policy_handover() = 0;
    virtual bool skip_unknown_robust_caching() = 0;
    virtual bool stack_sdp_detect_nil_property_type() = 0;
    virtual bool stack_sdp_disconnect_when_cancel_in_pending_state() = 0;
    virtual bool support_exclusive_manager() = 0;
    virtual bool support_metadata_device_types_apis() = 0;
    virtual bool suppress_hid_rejection_broadcast() = 0;
    virtual bool synchronous_bta_sec() = 0;
    virtual bool system_server_messenger() = 0;
    virtual bool temporary_pairing_device_properties() = 0;
    virtual bool uncache_player_when_browsed_player_changes() = 0;
    virtual bool unix_file_socket_creation_failure() = 0;
    virtual bool update_inquiry_result_on_flag_change() = 0;
    virtual bool use_dsp_codec_when_controller_does_not_support() = 0;
    virtual bool use_entire_message_handle() = 0;
    virtual bool use_le_shim_connection_map_guard() = 0;
    virtual bool use_local_oob_extended_command() = 0;
    virtual bool vcp_mute_unmute() = 0;
};

extern std::unique_ptr<flag_provider_interface> provider_;


inline bool a2dp_async_allow_low_latency() {
    return provider_->a2dp_async_allow_low_latency();
}
inline bool a2dp_concurrent_source_sink() {
    return provider_->a2dp_concurrent_source_sink();
}
inline bool a2dp_ignore_started_when_responder() {
    return provider_->a2dp_ignore_started_when_responder();
}
inline bool a2dp_offload_codec_extensibility() {
    return provider_->a2dp_offload_codec_extensibility();
}
inline bool a2dp_service_looper() {
    return provider_->a2dp_service_looper();
}
inline bool abs_volume_sdp_conflict() {
    return provider_->abs_volume_sdp_conflict();
}
inline bool airplane_mode_x_ble_on() {
    return provider_->airplane_mode_x_ble_on();
}
inline bool allow_switching_hid_and_hogp() {
    return provider_->allow_switching_hid_and_hogp();
}
inline bool android_headtracker_service() {
    return provider_->android_headtracker_service();
}
inline bool api_get_connection_state_using_identity_address() {
    return provider_->api_get_connection_state_using_identity_address();
}
inline bool asha_asrc() {
    return provider_->asha_asrc();
}
inline bool asymmetric_phy_for_unidirectional_cis() {
    return provider_->asymmetric_phy_for_unidirectional_cis();
}
inline bool audio_port_binder_inherit_rt() {
    return provider_->audio_port_binder_inherit_rt();
}
inline bool audio_routing_centralization() {
    return provider_->audio_routing_centralization();
}
inline bool auto_connect_on_hfp_when_no_a2dp_device() {
    return provider_->auto_connect_on_hfp_when_no_a2dp_device();
}
inline bool auto_connect_on_multiple_hfp_when_no_a2dp_device() {
    return provider_->auto_connect_on_multiple_hfp_when_no_a2dp_device();
}
inline bool auto_on_feature() {
    return provider_->auto_on_feature();
}
inline bool avdtp_error_codes() {
    return provider_->avdtp_error_codes();
}
inline bool avoid_static_loading_of_native() {
    return provider_->avoid_static_loading_of_native();
}
inline bool avrcp_connect_a2dp_delayed() {
    return provider_->avrcp_connect_a2dp_delayed();
}
inline bool avrcp_sdp_records() {
    return provider_->avrcp_sdp_records();
}
inline bool ble_check_data_length_on_legacy_advertising() {
    return provider_->ble_check_data_length_on_legacy_advertising();
}
inline bool ble_context_map_remove_fix() {
    return provider_->ble_context_map_remove_fix();
}
inline bool ble_gatt_server_use_address_type_in_connection() {
    return provider_->ble_gatt_server_use_address_type_in_connection();
}
inline bool ble_scan_adv_metrics_redesign() {
    return provider_->ble_scan_adv_metrics_redesign();
}
inline bool bluetooth_power_telemetry() {
    return provider_->bluetooth_power_telemetry();
}
inline bool bluffs_mitigation() {
    return provider_->bluffs_mitigation();
}
inline bool bond_transport_after_bond_cancel_fix() {
    return provider_->bond_transport_after_bond_cancel_fix();
}
inline bool break_uhid_polling_early() {
    return provider_->break_uhid_polling_early();
}
inline bool browsing_refactor() {
    return provider_->browsing_refactor();
}
inline bool bt_socket_api_l2cap_cid() {
    return provider_->bt_socket_api_l2cap_cid();
}
inline bool bt_system_context_report() {
    return provider_->bt_system_context_report();
}
inline bool bta_ag_cmd_brsf_allow_uint32() {
    return provider_->bta_ag_cmd_brsf_allow_uint32();
}
inline bool bta_av_setconfig_rej_type_confusion() {
    return provider_->bta_av_setconfig_rej_type_confusion();
}
inline bool bta_av_use_peer_codec() {
    return provider_->bta_av_use_peer_codec();
}
inline bool bta_dm_defer_device_discovery_state_change_until_rnr_complete() {
    return provider_->bta_dm_defer_device_discovery_state_change_until_rnr_complete();
}
inline bool bta_dm_disc_stuck_in_cancelling_fix() {
    return provider_->bta_dm_disc_stuck_in_cancelling_fix();
}
inline bool bta_dm_discover_both() {
    return provider_->bta_dm_discover_both();
}
inline bool cancel_pairing_only_on_disconnected_transport() {
    return provider_->cancel_pairing_only_on_disconnected_transport();
}
inline bool channel_sounding() {
    return provider_->channel_sounding();
}
inline bool channel_sounding_in_stack() {
    return provider_->channel_sounding_in_stack();
}
inline bool cleanup_le_only_device_type() {
    return provider_->cleanup_le_only_device_type();
}
inline bool clear_collision_state_on_pairing_complete() {
    return provider_->clear_collision_state_on_pairing_complete();
}
inline bool close_rfcomm_instead_of_reset() {
    return provider_->close_rfcomm_instead_of_reset();
}
inline bool connect_hid_after_service_discovery() {
    return provider_->connect_hid_after_service_discovery();
}
inline bool continue_service_discovery_when_cancel_device_discovery() {
    return provider_->continue_service_discovery_when_cancel_device_discovery();
}
inline bool correct_bond_type_of_loaded_devices() {
    return provider_->correct_bond_type_of_loaded_devices();
}
inline bool device_iot_config_logging() {
    return provider_->device_iot_config_logging();
}
inline bool divide_long_single_gap_data() {
    return provider_->divide_long_single_gap_data();
}
inline bool do_not_replace_existing_cod_with_uncategorized_cod() {
    return provider_->do_not_replace_existing_cod_with_uncategorized_cod();
}
inline bool dumpsys_acquire_stack_when_executing() {
    return provider_->dumpsys_acquire_stack_when_executing();
}
inline bool enable_hap_by_default() {
    return provider_->enable_hap_by_default();
}
inline bool enable_sniff_offload() {
    return provider_->enable_sniff_offload();
}
inline bool encrypted_advertising_data() {
    return provider_->encrypted_advertising_data();
}
inline bool ensure_valid_adv_flag() {
    return provider_->ensure_valid_adv_flag();
}
inline bool enumerate_gatt_errors() {
    return provider_->enumerate_gatt_errors();
}
inline bool explicit_kill_from_system_server() {
    return provider_->explicit_kill_from_system_server();
}
inline bool fast_bind_to_app() {
    return provider_->fast_bind_to_app();
}
inline bool fix_hfp_qual_1_9() {
    return provider_->fix_hfp_qual_1_9();
}
inline bool fix_le_oob_pairing_bypass() {
    return provider_->fix_le_oob_pairing_bypass();
}
inline bool fix_le_pairing_passkey_entry_bypass() {
    return provider_->fix_le_pairing_passkey_entry_bypass();
}
inline bool fix_nonconnectable_scannable_advertisement() {
    return provider_->fix_nonconnectable_scannable_advertisement();
}
inline bool fix_pairing_failure_reason_from_remote() {
    return provider_->fix_pairing_failure_reason_from_remote();
}
inline bool floss_separate_host_privacy_and_llprivacy() {
    return provider_->floss_separate_host_privacy_and_llprivacy();
}
inline bool force_bredr_for_sdp_retry() {
    return provider_->force_bredr_for_sdp_retry();
}
inline bool gatt_cleanup_restricted_handles() {
    return provider_->gatt_cleanup_restricted_handles();
}
inline bool gatt_drop_acl_on_out_of_resources_fix() {
    return provider_->gatt_drop_acl_on_out_of_resources_fix();
}
inline bool gatt_fix_device_busy() {
    return provider_->gatt_fix_device_busy();
}
inline bool gatt_reconnect_on_bt_on_fix() {
    return provider_->gatt_reconnect_on_bt_on_fix();
}
inline bool gatt_rediscover_on_canceled() {
    return provider_->gatt_rediscover_on_canceled();
}
inline bool gdx_device_discovery() {
    return provider_->gdx_device_discovery();
}
inline bool gdx_service_discovery() {
    return provider_->gdx_service_discovery();
}
inline bool get_address_type_api() {
    return provider_->get_address_type_api();
}
inline bool handle_delivery_sending_failure_events() {
    return provider_->handle_delivery_sending_failure_events();
}
inline bool headset_client_am_hf_volume_symmetric() {
    return provider_->headset_client_am_hf_volume_symmetric();
}
inline bool headtracker_codec_capability() {
    return provider_->headtracker_codec_capability();
}
inline bool hfp_codec_aptx_voice() {
    return provider_->hfp_codec_aptx_voice();
}
inline bool hid_report_queuing() {
    return provider_->hid_report_queuing();
}
inline bool higher_l2cap_flush_threshold() {
    return provider_->higher_l2cap_flush_threshold();
}
inline bool identity_address_null_if_unknown() {
    return provider_->identity_address_null_if_unknown();
}
inline bool ignore_bond_type_for_le() {
    return provider_->ignore_bond_type_for_le();
}
inline bool is_sco_managed_by_audio() {
    return provider_->is_sco_managed_by_audio();
}
inline bool keep_hfp_active_during_leaudio_handover() {
    return provider_->keep_hfp_active_during_leaudio_handover();
}
inline bool keep_stopped_media_browser_service() {
    return provider_->keep_stopped_media_browser_service();
}
inline bool key_missing_as_ordered_broadcast() {
    return provider_->key_missing_as_ordered_broadcast();
}
inline bool key_missing_broadcast() {
    return provider_->key_missing_broadcast();
}
inline bool key_missing_classic_device() {
    return provider_->key_missing_classic_device();
}
inline bool kill_instead_of_exit() {
    return provider_->kill_instead_of_exit();
}
inline bool l2cap_le_do_not_adjust_min_interval() {
    return provider_->l2cap_le_do_not_adjust_min_interval();
}
inline bool l2cap_p_ccb_check_rewrite() {
    return provider_->l2cap_p_ccb_check_rewrite();
}
inline bool l2cap_tx_complete_cb_info() {
    return provider_->l2cap_tx_complete_cb_info();
}
inline bool le_audio_base_ecosystem_interval() {
    return provider_->le_audio_base_ecosystem_interval();
}
inline bool le_audio_dev_type_detection_fix() {
    return provider_->le_audio_dev_type_detection_fix();
}
inline bool le_audio_support_unidirectional_voice_assistant() {
    return provider_->le_audio_support_unidirectional_voice_assistant();
}
inline bool le_periodic_scanning_reassembler() {
    return provider_->le_periodic_scanning_reassembler();
}
inline bool le_scan_fix_remote_exception() {
    return provider_->le_scan_fix_remote_exception();
}
inline bool le_scan_use_address_type() {
    return provider_->le_scan_use_address_type();
}
inline bool le_scan_use_uid_for_importance() {
    return provider_->le_scan_use_uid_for_importance();
}
inline bool leaudio_active_device_manager_group_handling_fix() {
    return provider_->leaudio_active_device_manager_group_handling_fix();
}
inline bool leaudio_add_sampling_frequencies() {
    return provider_->leaudio_add_sampling_frequencies();
}
inline bool leaudio_allow_leaudio_only_devices() {
    return provider_->leaudio_allow_leaudio_only_devices();
}
inline bool leaudio_allowed_context_mask() {
    return provider_->leaudio_allowed_context_mask();
}
inline bool leaudio_api_synchronized_block_fix() {
    return provider_->leaudio_api_synchronized_block_fix();
}
inline bool leaudio_big_depends_on_audio_state() {
    return provider_->leaudio_big_depends_on_audio_state();
}
inline bool leaudio_broadcast_assistant_handle_command_statuses() {
    return provider_->leaudio_broadcast_assistant_handle_command_statuses();
}
inline bool leaudio_broadcast_assistant_peripheral_entrustment() {
    return provider_->leaudio_broadcast_assistant_peripheral_entrustment();
}
inline bool leaudio_broadcast_audio_handover_policies() {
    return provider_->leaudio_broadcast_audio_handover_policies();
}
inline bool leaudio_broadcast_destroy_after_timeout() {
    return provider_->leaudio_broadcast_destroy_after_timeout();
}
inline bool leaudio_broadcast_extract_periodic_scanner_from_state_machine() {
    return provider_->leaudio_broadcast_extract_periodic_scanner_from_state_machine();
}
inline bool leaudio_broadcast_feature_support() {
    return provider_->leaudio_broadcast_feature_support();
}
inline bool leaudio_broadcast_monitor_source_sync_status() {
    return provider_->leaudio_broadcast_monitor_source_sync_status();
}
inline bool leaudio_broadcast_stop_on_streaming_request() {
    return provider_->leaudio_broadcast_stop_on_streaming_request();
}
inline bool leaudio_broadcast_volume_control_for_connected_devices() {
    return provider_->leaudio_broadcast_volume_control_for_connected_devices();
}
inline bool leaudio_broadcast_volume_control_with_set_volume() {
    return provider_->leaudio_broadcast_volume_control_with_set_volume();
}
inline bool leaudio_callback_on_group_stream_status() {
    return provider_->leaudio_callback_on_group_stream_status();
}
inline bool leaudio_codec_config_callback_order_fix() {
    return provider_->leaudio_codec_config_callback_order_fix();
}
inline bool leaudio_dynamic_spatial_audio() {
    return provider_->leaudio_dynamic_spatial_audio();
}
inline bool leaudio_enable_health_based_actions() {
    return provider_->leaudio_enable_health_based_actions();
}
inline bool leaudio_getting_active_state_support() {
    return provider_->leaudio_getting_active_state_support();
}
inline bool leaudio_hal_client_asrc() {
    return provider_->leaudio_hal_client_asrc();
}
inline bool leaudio_mcs_tbs_authorization_rebond_fix() {
    return provider_->leaudio_mcs_tbs_authorization_rebond_fix();
}
inline bool leaudio_mono_location_errata() {
    return provider_->leaudio_mono_location_errata();
}
inline bool leaudio_multicodec_aidl_support() {
    return provider_->leaudio_multicodec_aidl_support();
}
inline bool leaudio_multiple_vocs_instances_api() {
    return provider_->leaudio_multiple_vocs_instances_api();
}
inline bool leaudio_no_context_validate_streaming_request() {
    return provider_->leaudio_no_context_validate_streaming_request();
}
inline bool leaudio_quick_leaudio_toggle_switch_fix() {
    return provider_->leaudio_quick_leaudio_toggle_switch_fix();
}
inline bool leaudio_resume_active_after_hfp_handover() {
    return provider_->leaudio_resume_active_after_hfp_handover();
}
inline bool leaudio_start_request_state_mutex_check() {
    return provider_->leaudio_start_request_state_mutex_check();
}
inline bool leaudio_start_stream_race_fix() {
    return provider_->leaudio_start_stream_race_fix();
}
inline bool leaudio_synchronize_start() {
    return provider_->leaudio_synchronize_start();
}
inline bool leaudio_unicast_inactivate_device_based_on_context() {
    return provider_->leaudio_unicast_inactivate_device_based_on_context();
}
inline bool leaudio_use_audio_mode_listener() {
    return provider_->leaudio_use_audio_mode_listener();
}
inline bool leaudio_volume_change_on_ringtone_fix() {
    return provider_->leaudio_volume_change_on_ringtone_fix();
}
inline bool load_did_config_from_sysprops() {
    return provider_->load_did_config_from_sysprops();
}
inline bool map_limit_notification() {
    return provider_->map_limit_notification();
}
inline bool mcp_allow_play_without_active_player() {
    return provider_->mcp_allow_play_without_active_player();
}
inline bool metadata_api_inactive_audio_device_upon_connection() {
    return provider_->metadata_api_inactive_audio_device_upon_connection();
}
inline bool mfi_has_uuid() {
    return provider_->mfi_has_uuid();
}
inline bool msft_addr_tracking_quirk() {
    return provider_->msft_addr_tracking_quirk();
}
inline bool nrpa_non_connectable_adv() {
    return provider_->nrpa_non_connectable_adv();
}
inline bool opp_fix_multiple_notifications_issues() {
    return provider_->opp_fix_multiple_notifications_issues();
}
inline bool opp_ignore_content_observer_after_service_stop() {
    return provider_->opp_ignore_content_observer_after_service_stop();
}
inline bool opp_start_activity_directly_from_notification() {
    return provider_->opp_start_activity_directly_from_notification();
}
inline bool pairing_on_unknown_transport() {
    return provider_->pairing_on_unknown_transport();
}
inline bool phy_to_native() {
    return provider_->phy_to_native();
}
inline bool pretend_network_service() {
    return provider_->pretend_network_service();
}
inline bool prevent_hogp_reconnect_when_connected() {
    return provider_->prevent_hogp_reconnect_when_connected();
}
inline bool randomize_device_level_media_ids() {
    return provider_->randomize_device_level_media_ids();
}
inline bool read_model_num_fix() {
    return provider_->read_model_num_fix();
}
inline bool remove_address_map_on_unbond() {
    return provider_->remove_address_map_on_unbond();
}
inline bool reset_after_collision() {
    return provider_->reset_after_collision();
}
inline bool reset_ag_state_on_collision() {
    return provider_->reset_ag_state_on_collision();
}
inline bool reset_pairing_only_for_related_service_discovery() {
    return provider_->reset_pairing_only_for_related_service_discovery();
}
inline bool respect_ble_scan_setting() {
    return provider_->respect_ble_scan_setting();
}
inline bool retry_esco_with_zero_retransmission_effort() {
    return provider_->retry_esco_with_zero_retransmission_effort();
}
inline bool rfcomm_always_use_mitm() {
    return provider_->rfcomm_always_use_mitm();
}
inline bool rfcomm_bypass_post_to_main() {
    return provider_->rfcomm_bypass_post_to_main();
}
inline bool rnr_present_during_service_discovery() {
    return provider_->rnr_present_during_service_discovery();
}
inline bool rnr_reset_state_at_cancel() {
    return provider_->rnr_reset_state_at_cancel();
}
inline bool rnr_store_device_type() {
    return provider_->rnr_store_device_type();
}
inline bool rnr_validate_page_scan_repetition_mode() {
    return provider_->rnr_validate_page_scan_repetition_mode();
}
inline bool run_ble_audio_ticks_in_worker_thread() {
    return provider_->run_ble_audio_ticks_in_worker_thread();
}
inline bool run_clock_recovery_in_worker_thread() {
    return provider_->run_clock_recovery_in_worker_thread();
}
inline bool save_initial_hid_connection_policy() {
    return provider_->save_initial_hid_connection_policy();
}
inline bool scan_manager_refactor() {
    return provider_->scan_manager_refactor();
}
inline bool scan_record_manufacturer_data_merge() {
    return provider_->scan_record_manufacturer_data_merge();
}
inline bool sec_dont_clear_keys_on_encryption_err() {
    return provider_->sec_dont_clear_keys_on_encryption_err();
}
inline bool separate_service_and_device_discovery() {
    return provider_->separate_service_and_device_discovery();
}
inline bool settings_can_control_hap_preset() {
    return provider_->settings_can_control_hap_preset();
}
inline bool sink_audio_policy_handover() {
    return provider_->sink_audio_policy_handover();
}
inline bool skip_unknown_robust_caching() {
    return provider_->skip_unknown_robust_caching();
}
inline bool stack_sdp_detect_nil_property_type() {
    return provider_->stack_sdp_detect_nil_property_type();
}
inline bool stack_sdp_disconnect_when_cancel_in_pending_state() {
    return provider_->stack_sdp_disconnect_when_cancel_in_pending_state();
}
inline bool support_exclusive_manager() {
    return provider_->support_exclusive_manager();
}
inline bool support_metadata_device_types_apis() {
    return provider_->support_metadata_device_types_apis();
}
inline bool suppress_hid_rejection_broadcast() {
    return provider_->suppress_hid_rejection_broadcast();
}
inline bool synchronous_bta_sec() {
    return provider_->synchronous_bta_sec();
}
inline bool system_server_messenger() {
    return provider_->system_server_messenger();
}
inline bool temporary_pairing_device_properties() {
    return provider_->temporary_pairing_device_properties();
}
inline bool uncache_player_when_browsed_player_changes() {
    return provider_->uncache_player_when_browsed_player_changes();
}
inline bool unix_file_socket_creation_failure() {
    return provider_->unix_file_socket_creation_failure();
}
inline bool update_inquiry_result_on_flag_change() {
    return provider_->update_inquiry_result_on_flag_change();
}
inline bool use_dsp_codec_when_controller_does_not_support() {
    return provider_->use_dsp_codec_when_controller_does_not_support();
}
inline bool use_entire_message_handle() {
    return provider_->use_entire_message_handle();
}
inline bool use_le_shim_connection_map_guard() {
    return provider_->use_le_shim_connection_map_guard();
}
inline bool use_local_oob_extended_command() {
    return provider_->use_local_oob_extended_command();
}
inline bool vcp_mute_unmute() {
    return provider_->vcp_mute_unmute();
}

}

extern "C" {
#endif // __cplusplus


bool com_android_bluetooth_flags_a2dp_async_allow_low_latency();
bool com_android_bluetooth_flags_a2dp_concurrent_source_sink();
bool com_android_bluetooth_flags_a2dp_ignore_started_when_responder();
bool com_android_bluetooth_flags_a2dp_offload_codec_extensibility();
bool com_android_bluetooth_flags_a2dp_service_looper();
bool com_android_bluetooth_flags_abs_volume_sdp_conflict();
bool com_android_bluetooth_flags_airplane_mode_x_ble_on();
bool com_android_bluetooth_flags_allow_switching_hid_and_hogp();
bool com_android_bluetooth_flags_android_headtracker_service();
bool com_android_bluetooth_flags_api_get_connection_state_using_identity_address();
bool com_android_bluetooth_flags_asha_asrc();
bool com_android_bluetooth_flags_asymmetric_phy_for_unidirectional_cis();
bool com_android_bluetooth_flags_audio_port_binder_inherit_rt();
bool com_android_bluetooth_flags_audio_routing_centralization();
bool com_android_bluetooth_flags_auto_connect_on_hfp_when_no_a2dp_device();
bool com_android_bluetooth_flags_auto_connect_on_multiple_hfp_when_no_a2dp_device();
bool com_android_bluetooth_flags_auto_on_feature();
bool com_android_bluetooth_flags_avdtp_error_codes();
bool com_android_bluetooth_flags_avoid_static_loading_of_native();
bool com_android_bluetooth_flags_avrcp_connect_a2dp_delayed();
bool com_android_bluetooth_flags_avrcp_sdp_records();
bool com_android_bluetooth_flags_ble_check_data_length_on_legacy_advertising();
bool com_android_bluetooth_flags_ble_context_map_remove_fix();
bool com_android_bluetooth_flags_ble_gatt_server_use_address_type_in_connection();
bool com_android_bluetooth_flags_ble_scan_adv_metrics_redesign();
bool com_android_bluetooth_flags_bluetooth_power_telemetry();
bool com_android_bluetooth_flags_bluffs_mitigation();
bool com_android_bluetooth_flags_bond_transport_after_bond_cancel_fix();
bool com_android_bluetooth_flags_break_uhid_polling_early();
bool com_android_bluetooth_flags_browsing_refactor();
bool com_android_bluetooth_flags_bt_socket_api_l2cap_cid();
bool com_android_bluetooth_flags_bt_system_context_report();
bool com_android_bluetooth_flags_bta_ag_cmd_brsf_allow_uint32();
bool com_android_bluetooth_flags_bta_av_setconfig_rej_type_confusion();
bool com_android_bluetooth_flags_bta_av_use_peer_codec();
bool com_android_bluetooth_flags_bta_dm_defer_device_discovery_state_change_until_rnr_complete();
bool com_android_bluetooth_flags_bta_dm_disc_stuck_in_cancelling_fix();
bool com_android_bluetooth_flags_bta_dm_discover_both();
bool com_android_bluetooth_flags_cancel_pairing_only_on_disconnected_transport();
bool com_android_bluetooth_flags_channel_sounding();
bool com_android_bluetooth_flags_channel_sounding_in_stack();
bool com_android_bluetooth_flags_cleanup_le_only_device_type();
bool com_android_bluetooth_flags_clear_collision_state_on_pairing_complete();
bool com_android_bluetooth_flags_close_rfcomm_instead_of_reset();
bool com_android_bluetooth_flags_connect_hid_after_service_discovery();
bool com_android_bluetooth_flags_continue_service_discovery_when_cancel_device_discovery();
bool com_android_bluetooth_flags_correct_bond_type_of_loaded_devices();
bool com_android_bluetooth_flags_device_iot_config_logging();
bool com_android_bluetooth_flags_divide_long_single_gap_data();
bool com_android_bluetooth_flags_do_not_replace_existing_cod_with_uncategorized_cod();
bool com_android_bluetooth_flags_dumpsys_acquire_stack_when_executing();
bool com_android_bluetooth_flags_enable_hap_by_default();
bool com_android_bluetooth_flags_enable_sniff_offload();
bool com_android_bluetooth_flags_encrypted_advertising_data();
bool com_android_bluetooth_flags_ensure_valid_adv_flag();
bool com_android_bluetooth_flags_enumerate_gatt_errors();
bool com_android_bluetooth_flags_explicit_kill_from_system_server();
bool com_android_bluetooth_flags_fast_bind_to_app();
bool com_android_bluetooth_flags_fix_hfp_qual_1_9();
bool com_android_bluetooth_flags_fix_le_oob_pairing_bypass();
bool com_android_bluetooth_flags_fix_le_pairing_passkey_entry_bypass();
bool com_android_bluetooth_flags_fix_nonconnectable_scannable_advertisement();
bool com_android_bluetooth_flags_fix_pairing_failure_reason_from_remote();
bool com_android_bluetooth_flags_floss_separate_host_privacy_and_llprivacy();
bool com_android_bluetooth_flags_force_bredr_for_sdp_retry();
bool com_android_bluetooth_flags_gatt_cleanup_restricted_handles();
bool com_android_bluetooth_flags_gatt_drop_acl_on_out_of_resources_fix();
bool com_android_bluetooth_flags_gatt_fix_device_busy();
bool com_android_bluetooth_flags_gatt_reconnect_on_bt_on_fix();
bool com_android_bluetooth_flags_gatt_rediscover_on_canceled();
bool com_android_bluetooth_flags_gdx_device_discovery();
bool com_android_bluetooth_flags_gdx_service_discovery();
bool com_android_bluetooth_flags_get_address_type_api();
bool com_android_bluetooth_flags_handle_delivery_sending_failure_events();
bool com_android_bluetooth_flags_headset_client_am_hf_volume_symmetric();
bool com_android_bluetooth_flags_headtracker_codec_capability();
bool com_android_bluetooth_flags_hfp_codec_aptx_voice();
bool com_android_bluetooth_flags_hid_report_queuing();
bool com_android_bluetooth_flags_higher_l2cap_flush_threshold();
bool com_android_bluetooth_flags_identity_address_null_if_unknown();
bool com_android_bluetooth_flags_ignore_bond_type_for_le();
bool com_android_bluetooth_flags_is_sco_managed_by_audio();
bool com_android_bluetooth_flags_keep_hfp_active_during_leaudio_handover();
bool com_android_bluetooth_flags_keep_stopped_media_browser_service();
bool com_android_bluetooth_flags_key_missing_as_ordered_broadcast();
bool com_android_bluetooth_flags_key_missing_broadcast();
bool com_android_bluetooth_flags_key_missing_classic_device();
bool com_android_bluetooth_flags_kill_instead_of_exit();
bool com_android_bluetooth_flags_l2cap_le_do_not_adjust_min_interval();
bool com_android_bluetooth_flags_l2cap_p_ccb_check_rewrite();
bool com_android_bluetooth_flags_l2cap_tx_complete_cb_info();
bool com_android_bluetooth_flags_le_audio_base_ecosystem_interval();
bool com_android_bluetooth_flags_le_audio_dev_type_detection_fix();
bool com_android_bluetooth_flags_le_audio_support_unidirectional_voice_assistant();
bool com_android_bluetooth_flags_le_periodic_scanning_reassembler();
bool com_android_bluetooth_flags_le_scan_fix_remote_exception();
bool com_android_bluetooth_flags_le_scan_use_address_type();
bool com_android_bluetooth_flags_le_scan_use_uid_for_importance();
bool com_android_bluetooth_flags_leaudio_active_device_manager_group_handling_fix();
bool com_android_bluetooth_flags_leaudio_add_sampling_frequencies();
bool com_android_bluetooth_flags_leaudio_allow_leaudio_only_devices();
bool com_android_bluetooth_flags_leaudio_allowed_context_mask();
bool com_android_bluetooth_flags_leaudio_api_synchronized_block_fix();
bool com_android_bluetooth_flags_leaudio_big_depends_on_audio_state();
bool com_android_bluetooth_flags_leaudio_broadcast_assistant_handle_command_statuses();
bool com_android_bluetooth_flags_leaudio_broadcast_assistant_peripheral_entrustment();
bool com_android_bluetooth_flags_leaudio_broadcast_audio_handover_policies();
bool com_android_bluetooth_flags_leaudio_broadcast_destroy_after_timeout();
bool com_android_bluetooth_flags_leaudio_broadcast_extract_periodic_scanner_from_state_machine();
bool com_android_bluetooth_flags_leaudio_broadcast_feature_support();
bool com_android_bluetooth_flags_leaudio_broadcast_monitor_source_sync_status();
bool com_android_bluetooth_flags_leaudio_broadcast_stop_on_streaming_request();
bool com_android_bluetooth_flags_leaudio_broadcast_volume_control_for_connected_devices();
bool com_android_bluetooth_flags_leaudio_broadcast_volume_control_with_set_volume();
bool com_android_bluetooth_flags_leaudio_callback_on_group_stream_status();
bool com_android_bluetooth_flags_leaudio_codec_config_callback_order_fix();
bool com_android_bluetooth_flags_leaudio_dynamic_spatial_audio();
bool com_android_bluetooth_flags_leaudio_enable_health_based_actions();
bool com_android_bluetooth_flags_leaudio_getting_active_state_support();
bool com_android_bluetooth_flags_leaudio_hal_client_asrc();
bool com_android_bluetooth_flags_leaudio_mcs_tbs_authorization_rebond_fix();
bool com_android_bluetooth_flags_leaudio_mono_location_errata();
bool com_android_bluetooth_flags_leaudio_multicodec_aidl_support();
bool com_android_bluetooth_flags_leaudio_multiple_vocs_instances_api();
bool com_android_bluetooth_flags_leaudio_no_context_validate_streaming_request();
bool com_android_bluetooth_flags_leaudio_quick_leaudio_toggle_switch_fix();
bool com_android_bluetooth_flags_leaudio_resume_active_after_hfp_handover();
bool com_android_bluetooth_flags_leaudio_start_request_state_mutex_check();
bool com_android_bluetooth_flags_leaudio_start_stream_race_fix();
bool com_android_bluetooth_flags_leaudio_synchronize_start();
bool com_android_bluetooth_flags_leaudio_unicast_inactivate_device_based_on_context();
bool com_android_bluetooth_flags_leaudio_use_audio_mode_listener();
bool com_android_bluetooth_flags_leaudio_volume_change_on_ringtone_fix();
bool com_android_bluetooth_flags_load_did_config_from_sysprops();
bool com_android_bluetooth_flags_map_limit_notification();
bool com_android_bluetooth_flags_mcp_allow_play_without_active_player();
bool com_android_bluetooth_flags_metadata_api_inactive_audio_device_upon_connection();
bool com_android_bluetooth_flags_mfi_has_uuid();
bool com_android_bluetooth_flags_msft_addr_tracking_quirk();
bool com_android_bluetooth_flags_nrpa_non_connectable_adv();
bool com_android_bluetooth_flags_opp_fix_multiple_notifications_issues();
bool com_android_bluetooth_flags_opp_ignore_content_observer_after_service_stop();
bool com_android_bluetooth_flags_opp_start_activity_directly_from_notification();
bool com_android_bluetooth_flags_pairing_on_unknown_transport();
bool com_android_bluetooth_flags_phy_to_native();
bool com_android_bluetooth_flags_pretend_network_service();
bool com_android_bluetooth_flags_prevent_hogp_reconnect_when_connected();
bool com_android_bluetooth_flags_randomize_device_level_media_ids();
bool com_android_bluetooth_flags_read_model_num_fix();
bool com_android_bluetooth_flags_remove_address_map_on_unbond();
bool com_android_bluetooth_flags_reset_after_collision();
bool com_android_bluetooth_flags_reset_ag_state_on_collision();
bool com_android_bluetooth_flags_reset_pairing_only_for_related_service_discovery();
bool com_android_bluetooth_flags_respect_ble_scan_setting();
bool com_android_bluetooth_flags_retry_esco_with_zero_retransmission_effort();
bool com_android_bluetooth_flags_rfcomm_always_use_mitm();
bool com_android_bluetooth_flags_rfcomm_bypass_post_to_main();
bool com_android_bluetooth_flags_rnr_present_during_service_discovery();
bool com_android_bluetooth_flags_rnr_reset_state_at_cancel();
bool com_android_bluetooth_flags_rnr_store_device_type();
bool com_android_bluetooth_flags_rnr_validate_page_scan_repetition_mode();
bool com_android_bluetooth_flags_run_ble_audio_ticks_in_worker_thread();
bool com_android_bluetooth_flags_run_clock_recovery_in_worker_thread();
bool com_android_bluetooth_flags_save_initial_hid_connection_policy();
bool com_android_bluetooth_flags_scan_manager_refactor();
bool com_android_bluetooth_flags_scan_record_manufacturer_data_merge();
bool com_android_bluetooth_flags_sec_dont_clear_keys_on_encryption_err();
bool com_android_bluetooth_flags_separate_service_and_device_discovery();
bool com_android_bluetooth_flags_settings_can_control_hap_preset();
bool com_android_bluetooth_flags_sink_audio_policy_handover();
bool com_android_bluetooth_flags_skip_unknown_robust_caching();
bool com_android_bluetooth_flags_stack_sdp_detect_nil_property_type();
bool com_android_bluetooth_flags_stack_sdp_disconnect_when_cancel_in_pending_state();
bool com_android_bluetooth_flags_support_exclusive_manager();
bool com_android_bluetooth_flags_support_metadata_device_types_apis();
bool com_android_bluetooth_flags_suppress_hid_rejection_broadcast();
bool com_android_bluetooth_flags_synchronous_bta_sec();
bool com_android_bluetooth_flags_system_server_messenger();
bool com_android_bluetooth_flags_temporary_pairing_device_properties();
bool com_android_bluetooth_flags_uncache_player_when_browsed_player_changes();
bool com_android_bluetooth_flags_unix_file_socket_creation_failure();
bool com_android_bluetooth_flags_update_inquiry_result_on_flag_change();
bool com_android_bluetooth_flags_use_dsp_codec_when_controller_does_not_support();
bool com_android_bluetooth_flags_use_entire_message_handle();
bool com_android_bluetooth_flags_use_le_shim_connection_map_guard();
bool com_android_bluetooth_flags_use_local_oob_extended_command();
bool com_android_bluetooth_flags_vcp_mute_unmute();

#ifdef __cplusplus
} // extern "C"
#endif

