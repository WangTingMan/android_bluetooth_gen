#include "com_android_bluetooth_flags.h"



#include <server_configurable_flags/get_flags.h>

#include <vector>

namespace com::android::bluetooth::flags {

class flag_provider : public flag_provider_interface {
    public:

        virtual bool a2dp_async_allow_low_latency() override {
            if (cache_[0] == -1) {
                cache_[0] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.a2dp_async_allow_low_latency",
                    "true") == "true";
            }
            return cache_[0];
        }

        virtual bool a2dp_concurrent_source_sink() override {
            if (cache_[1] == -1) {
                cache_[1] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.a2dp_concurrent_source_sink",
                    "true") == "true";
            }
            return cache_[1];
        }

        virtual bool a2dp_ignore_started_when_responder() override {
            if (cache_[2] == -1) {
                cache_[2] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.a2dp_ignore_started_when_responder",
                    "false") == "true";
            }
            return cache_[2];
        }

        virtual bool a2dp_offload_codec_extensibility() override {
            if (cache_[3] == -1) {
                cache_[3] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.a2dp_offload_codec_extensibility",
                    "true") == "true";
            }
            return cache_[3];
        }

        virtual bool a2dp_service_looper() override {
            if (cache_[4] == -1) {
                cache_[4] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.a2dp_service_looper",
                    "false") == "true";
            }
            return cache_[4];
        }

        virtual bool abs_volume_sdp_conflict() override {
            if (cache_[5] == -1) {
                cache_[5] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.abs_volume_sdp_conflict",
                    "false") == "true";
            }
            return cache_[5];
        }

        virtual bool airplane_mode_x_ble_on() override {
            if (cache_[6] == -1) {
                cache_[6] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.airplane_mode_x_ble_on",
                    "true") == "true";
            }
            return cache_[6];
        }

        virtual bool allow_switching_hid_and_hogp() override {
            if (cache_[7] == -1) {
                cache_[7] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.allow_switching_hid_and_hogp",
                    "true") == "true";
            }
            return cache_[7];
        }

        virtual bool android_headtracker_service() override {
            if (cache_[8] == -1) {
                cache_[8] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.android_headtracker_service",
                    "true") == "true";
            }
            return cache_[8];
        }

        virtual bool api_get_connection_state_using_identity_address() override {
            if (cache_[9] == -1) {
                cache_[9] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.api_get_connection_state_using_identity_address",
                    "true") == "true";
            }
            return cache_[9];
        }

        virtual bool asha_asrc() override {
            if (cache_[10] == -1) {
                cache_[10] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.asha_asrc",
                    "true") == "true";
            }
            return cache_[10];
        }

        virtual bool asymmetric_phy_for_unidirectional_cis() override {
            if (cache_[11] == -1) {
                cache_[11] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.asymmetric_phy_for_unidirectional_cis",
                    "true") == "true";
            }
            return cache_[11];
        }

        virtual bool audio_port_binder_inherit_rt() override {
            if (cache_[12] == -1) {
                cache_[12] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.audio_port_binder_inherit_rt",
                    "false") == "true";
            }
            return cache_[12];
        }

        virtual bool audio_routing_centralization() override {
            if (cache_[13] == -1) {
                cache_[13] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.audio_routing_centralization",
                    "false") == "true";
            }
            return cache_[13];
        }

        virtual bool auto_connect_on_hfp_when_no_a2dp_device() override {
            if (cache_[14] == -1) {
                cache_[14] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.auto_connect_on_hfp_when_no_a2dp_device",
                    "true") == "true";
            }
            return cache_[14];
        }

        virtual bool auto_connect_on_multiple_hfp_when_no_a2dp_device() override {
            if (cache_[15] == -1) {
                cache_[15] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.auto_connect_on_multiple_hfp_when_no_a2dp_device",
                    "false") == "true";
            }
            return cache_[15];
        }

        virtual bool auto_on_feature() override {
            if (cache_[16] == -1) {
                cache_[16] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.auto_on_feature",
                    "true") == "true";
            }
            return cache_[16];
        }

        virtual bool avdtp_error_codes() override {
            if (cache_[17] == -1) {
                cache_[17] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.avdtp_error_codes",
                    "false") == "true";
            }
            return cache_[17];
        }

        virtual bool avoid_static_loading_of_native() override {
            if (cache_[18] == -1) {
                cache_[18] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.avoid_static_loading_of_native",
                    "false") == "true";
            }
            return cache_[18];
        }

        virtual bool avrcp_connect_a2dp_delayed() override {
            if (cache_[19] == -1) {
                cache_[19] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.avrcp_connect_a2dp_delayed",
                    "false") == "true";
            }
            return cache_[19];
        }

        virtual bool avrcp_sdp_records() override {
            if (cache_[20] == -1) {
                cache_[20] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.avrcp_sdp_records",
                    "false") == "true";
            }
            return cache_[20];
        }

        virtual bool ble_check_data_length_on_legacy_advertising() override {
            if (cache_[21] == -1) {
                cache_[21] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.ble_check_data_length_on_legacy_advertising",
                    "true") == "true";
            }
            return cache_[21];
        }

        virtual bool ble_context_map_remove_fix() override {
            if (cache_[22] == -1) {
                cache_[22] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.ble_context_map_remove_fix",
                    "false") == "true";
            }
            return cache_[22];
        }

        virtual bool ble_gatt_server_use_address_type_in_connection() override {
            if (cache_[23] == -1) {
                cache_[23] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.ble_gatt_server_use_address_type_in_connection",
                    "true") == "true";
            }
            return cache_[23];
        }

        virtual bool ble_scan_adv_metrics_redesign() override {
            if (cache_[24] == -1) {
                cache_[24] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.ble_scan_adv_metrics_redesign",
                    "false") == "true";
            }
            return cache_[24];
        }

        virtual bool bluetooth_power_telemetry() override {
            if (cache_[25] == -1) {
                cache_[25] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.bluetooth_power_telemetry",
                    "false") == "true";
            }
            return cache_[25];
        }

        virtual bool bluffs_mitigation() override {
            if (cache_[26] == -1) {
                cache_[26] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.bluffs_mitigation",
                    "true") == "true";
            }
            return cache_[26];
        }

        virtual bool bond_transport_after_bond_cancel_fix() override {
            if (cache_[27] == -1) {
                cache_[27] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.bond_transport_after_bond_cancel_fix",
                    "false") == "true";
            }
            return cache_[27];
        }

        virtual bool break_uhid_polling_early() override {
            if (cache_[28] == -1) {
                cache_[28] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.break_uhid_polling_early",
                    "true") == "true";
            }
            return cache_[28];
        }

        virtual bool browsing_refactor() override {
            if (cache_[29] == -1) {
                cache_[29] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.browsing_refactor",
                    "false") == "true";
            }
            return cache_[29];
        }

        virtual bool bt_socket_api_l2cap_cid() override {
            if (cache_[30] == -1) {
                cache_[30] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.bt_socket_api_l2cap_cid",
                    "false") == "true";
            }
            return cache_[30];
        }

        virtual bool bt_system_context_report() override {
            if (cache_[31] == -1) {
                cache_[31] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.bt_system_context_report",
                    "true") == "true";
            }
            return cache_[31];
        }

        virtual bool bta_ag_cmd_brsf_allow_uint32() override {
            if (cache_[32] == -1) {
                cache_[32] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.bta_ag_cmd_brsf_allow_uint32",
                    "false") == "true";
            }
            return cache_[32];
        }

        virtual bool bta_av_setconfig_rej_type_confusion() override {
            if (cache_[33] == -1) {
                cache_[33] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.bta_av_setconfig_rej_type_confusion",
                    "false") == "true";
            }
            return cache_[33];
        }

        virtual bool bta_av_use_peer_codec() override {
            if (cache_[34] == -1) {
                cache_[34] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.bta_av_use_peer_codec",
                    "false") == "true";
            }
            return cache_[34];
        }

        virtual bool bta_dm_defer_device_discovery_state_change_until_rnr_complete() override {
            if (cache_[35] == -1) {
                cache_[35] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.bta_dm_defer_device_discovery_state_change_until_rnr_complete",
                    "false") == "true";
            }
            return cache_[35];
        }

        virtual bool bta_dm_disc_stuck_in_cancelling_fix() override {
            if (cache_[36] == -1) {
                cache_[36] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.bta_dm_disc_stuck_in_cancelling_fix",
                    "true") == "true";
            }
            return cache_[36];
        }

        virtual bool bta_dm_discover_both() override {
            if (cache_[37] == -1) {
                cache_[37] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.bta_dm_discover_both",
                    "false") == "true";
            }
            return cache_[37];
        }

        virtual bool cancel_pairing_only_on_disconnected_transport() override {
            if (cache_[38] == -1) {
                cache_[38] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.cancel_pairing_only_on_disconnected_transport",
                    "false") == "true";
            }
            return cache_[38];
        }

        virtual bool channel_sounding() override {
            if (cache_[39] == -1) {
                cache_[39] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.channel_sounding",
                    "true") == "true";
            }
            return cache_[39];
        }

        virtual bool channel_sounding_in_stack() override {
            if (cache_[40] == -1) {
                cache_[40] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.channel_sounding_in_stack",
                    "false") == "true";
            }
            return cache_[40];
        }

        virtual bool cleanup_le_only_device_type() override {
            if (cache_[41] == -1) {
                cache_[41] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.cleanup_le_only_device_type",
                    "true") == "true";
            }
            return cache_[41];
        }

        virtual bool clear_collision_state_on_pairing_complete() override {
            if (cache_[42] == -1) {
                cache_[42] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.clear_collision_state_on_pairing_complete",
                    "false") == "true";
            }
            return cache_[42];
        }

        virtual bool close_rfcomm_instead_of_reset() override {
            if (cache_[43] == -1) {
                cache_[43] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.close_rfcomm_instead_of_reset",
                    "true") == "true";
            }
            return cache_[43];
        }

        virtual bool connect_hid_after_service_discovery() override {
            if (cache_[44] == -1) {
                cache_[44] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.connect_hid_after_service_discovery",
                    "true") == "true";
            }
            return cache_[44];
        }

        virtual bool continue_service_discovery_when_cancel_device_discovery() override {
            if (cache_[45] == -1) {
                cache_[45] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.continue_service_discovery_when_cancel_device_discovery",
                    "false") == "true";
            }
            return cache_[45];
        }

        virtual bool correct_bond_type_of_loaded_devices() override {
            if (cache_[46] == -1) {
                cache_[46] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.correct_bond_type_of_loaded_devices",
                    "true") == "true";
            }
            return cache_[46];
        }

        virtual bool device_iot_config_logging() override {
            if (cache_[47] == -1) {
                cache_[47] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.device_iot_config_logging",
                    "false") == "true";
            }
            return cache_[47];
        }

        virtual bool divide_long_single_gap_data() override {
            if (cache_[48] == -1) {
                cache_[48] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.divide_long_single_gap_data",
                    "true") == "true";
            }
            return cache_[48];
        }

        virtual bool do_not_replace_existing_cod_with_uncategorized_cod() override {
            if (cache_[49] == -1) {
                cache_[49] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.do_not_replace_existing_cod_with_uncategorized_cod",
                    "true") == "true";
            }
            return cache_[49];
        }

        virtual bool dumpsys_acquire_stack_when_executing() override {
            if (cache_[50] == -1) {
                cache_[50] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.dumpsys_acquire_stack_when_executing",
                    "true") == "true";
            }
            return cache_[50];
        }

        virtual bool enable_hap_by_default() override {
            if (cache_[51] == -1) {
                cache_[51] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.enable_hap_by_default",
                    "false") == "true";
            }
            return cache_[51];
        }

        virtual bool enable_sniff_offload() override {
            if (cache_[52] == -1) {
                cache_[52] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.enable_sniff_offload",
                    "false") == "true";
            }
            return cache_[52];
        }

        virtual bool encrypted_advertising_data() override {
            if (cache_[53] == -1) {
                cache_[53] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.encrypted_advertising_data",
                    "false") == "true";
            }
            return cache_[53];
        }

        virtual bool ensure_valid_adv_flag() override {
            if (cache_[54] == -1) {
                cache_[54] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.ensure_valid_adv_flag",
                    "true") == "true";
            }
            return cache_[54];
        }

        virtual bool enumerate_gatt_errors() override {
            if (cache_[55] == -1) {
                cache_[55] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.enumerate_gatt_errors",
                    "true") == "true";
            }
            return cache_[55];
        }

        virtual bool explicit_kill_from_system_server() override {
            if (cache_[56] == -1) {
                cache_[56] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.explicit_kill_from_system_server",
                    "false") == "true";
            }
            return cache_[56];
        }

        virtual bool fast_bind_to_app() override {
            if (cache_[57] == -1) {
                cache_[57] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.fast_bind_to_app",
                    "false") == "true";
            }
            return cache_[57];
        }

        virtual bool fix_hfp_qual_1_9() override {
            if (cache_[58] == -1) {
                cache_[58] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.fix_hfp_qual_1_9",
                    "false") == "true";
            }
            return cache_[58];
        }

        virtual bool fix_le_oob_pairing_bypass() override {
            if (cache_[59] == -1) {
                cache_[59] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.fix_le_oob_pairing_bypass",
                    "true") == "true";
            }
            return cache_[59];
        }

        virtual bool fix_le_pairing_passkey_entry_bypass() override {
            if (cache_[60] == -1) {
                cache_[60] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.fix_le_pairing_passkey_entry_bypass",
                    "true") == "true";
            }
            return cache_[60];
        }

        virtual bool fix_nonconnectable_scannable_advertisement() override {
            if (cache_[61] == -1) {
                cache_[61] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.fix_nonconnectable_scannable_advertisement",
                    "true") == "true";
            }
            return cache_[61];
        }

        virtual bool fix_pairing_failure_reason_from_remote() override {
            if (cache_[62] == -1) {
                cache_[62] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.fix_pairing_failure_reason_from_remote",
                    "true") == "true";
            }
            return cache_[62];
        }

        virtual bool floss_separate_host_privacy_and_llprivacy() override {
            if (cache_[63] == -1) {
                cache_[63] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.floss_separate_host_privacy_and_llprivacy",
                    "false") == "true";
            }
            return cache_[63];
        }

        virtual bool force_bredr_for_sdp_retry() override {
            if (cache_[64] == -1) {
                cache_[64] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.force_bredr_for_sdp_retry",
                    "true") == "true";
            }
            return cache_[64];
        }

        virtual bool gatt_cleanup_restricted_handles() override {
            if (cache_[65] == -1) {
                cache_[65] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.gatt_cleanup_restricted_handles",
                    "true") == "true";
            }
            return cache_[65];
        }

        virtual bool gatt_drop_acl_on_out_of_resources_fix() override {
            if (cache_[66] == -1) {
                cache_[66] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.gatt_drop_acl_on_out_of_resources_fix",
                    "true") == "true";
            }
            return cache_[66];
        }

        virtual bool gatt_fix_device_busy() override {
            if (cache_[67] == -1) {
                cache_[67] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.gatt_fix_device_busy",
                    "true") == "true";
            }
            return cache_[67];
        }

        virtual bool gatt_reconnect_on_bt_on_fix() override {
            if (cache_[68] == -1) {
                cache_[68] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.gatt_reconnect_on_bt_on_fix",
                    "true") == "true";
            }
            return cache_[68];
        }

        virtual bool gatt_rediscover_on_canceled() override {
            if (cache_[69] == -1) {
                cache_[69] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.gatt_rediscover_on_canceled",
                    "true") == "true";
            }
            return cache_[69];
        }

        virtual bool gdx_device_discovery() override {
            if (cache_[70] == -1) {
                cache_[70] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.gdx_device_discovery",
                    "false") == "true";
            }
            return cache_[70];
        }

        virtual bool gdx_service_discovery() override {
            if (cache_[71] == -1) {
                cache_[71] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.gdx_service_discovery",
                    "false") == "true";
            }
            return cache_[71];
        }

        virtual bool get_address_type_api() override {
            if (cache_[72] == -1) {
                cache_[72] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.get_address_type_api",
                    "true") == "true";
            }
            return cache_[72];
        }

        virtual bool handle_delivery_sending_failure_events() override {
            if (cache_[73] == -1) {
                cache_[73] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.handle_delivery_sending_failure_events",
                    "false") == "true";
            }
            return cache_[73];
        }

        virtual bool headset_client_am_hf_volume_symmetric() override {
            if (cache_[74] == -1) {
                cache_[74] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.headset_client_am_hf_volume_symmetric",
                    "false") == "true";
            }
            return cache_[74];
        }

        virtual bool headtracker_codec_capability() override {
            if (cache_[75] == -1) {
                cache_[75] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.headtracker_codec_capability",
                    "true") == "true";
            }
            return cache_[75];
        }

        virtual bool hfp_codec_aptx_voice() override {
            if (cache_[76] == -1) {
                cache_[76] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.hfp_codec_aptx_voice",
                    "true") == "true";
            }
            return cache_[76];
        }

        virtual bool hid_report_queuing() override {
            if (cache_[77] == -1) {
                cache_[77] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.hid_report_queuing",
                    "false") == "true";
            }
            return cache_[77];
        }

        virtual bool higher_l2cap_flush_threshold() override {
            if (cache_[78] == -1) {
                cache_[78] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.higher_l2cap_flush_threshold",
                    "false") == "true";
            }
            return cache_[78];
        }

        virtual bool identity_address_null_if_unknown() override {
            if (cache_[79] == -1) {
                cache_[79] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.identity_address_null_if_unknown",
                    "false") == "true";
            }
            return cache_[79];
        }

        virtual bool ignore_bond_type_for_le() override {
            if (cache_[80] == -1) {
                cache_[80] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.ignore_bond_type_for_le",
                    "true") == "true";
            }
            return cache_[80];
        }

        virtual bool is_sco_managed_by_audio() override {
            if (cache_[81] == -1) {
                cache_[81] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.is_sco_managed_by_audio",
                    "false") == "true";
            }
            return cache_[81];
        }

        virtual bool keep_hfp_active_during_leaudio_handover() override {
            if (cache_[82] == -1) {
                cache_[82] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.keep_hfp_active_during_leaudio_handover",
                    "true") == "true";
            }
            return cache_[82];
        }

        virtual bool keep_stopped_media_browser_service() override {
            if (cache_[83] == -1) {
                cache_[83] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.keep_stopped_media_browser_service",
                    "true") == "true";
            }
            return cache_[83];
        }

        virtual bool key_missing_as_ordered_broadcast() override {
            if (cache_[84] == -1) {
                cache_[84] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.key_missing_as_ordered_broadcast",
                    "false") == "true";
            }
            return cache_[84];
        }

        virtual bool key_missing_broadcast() override {
            if (cache_[85] == -1) {
                cache_[85] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.key_missing_broadcast",
                    "true") == "true";
            }
            return cache_[85];
        }

        virtual bool key_missing_classic_device() override {
            if (cache_[86] == -1) {
                cache_[86] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.key_missing_classic_device",
                    "false") == "true";
            }
            return cache_[86];
        }

        virtual bool kill_instead_of_exit() override {
            if (cache_[87] == -1) {
                cache_[87] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.kill_instead_of_exit",
                    "false") == "true";
            }
            return cache_[87];
        }

        virtual bool l2cap_le_do_not_adjust_min_interval() override {
            if (cache_[88] == -1) {
                cache_[88] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.l2cap_le_do_not_adjust_min_interval",
                    "false") == "true";
            }
            return cache_[88];
        }

        virtual bool l2cap_p_ccb_check_rewrite() override {
            if (cache_[89] == -1) {
                cache_[89] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.l2cap_p_ccb_check_rewrite",
                    "false") == "true";
            }
            return cache_[89];
        }

        virtual bool l2cap_tx_complete_cb_info() override {
            if (cache_[90] == -1) {
                cache_[90] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.l2cap_tx_complete_cb_info",
                    "false") == "true";
            }
            return cache_[90];
        }

        virtual bool le_audio_base_ecosystem_interval() override {
            if (cache_[91] == -1) {
                cache_[91] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.le_audio_base_ecosystem_interval",
                    "false") == "true";
            }
            return cache_[91];
        }

        virtual bool le_audio_dev_type_detection_fix() override {
            if (cache_[92] == -1) {
                cache_[92] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.le_audio_dev_type_detection_fix",
                    "true") == "true";
            }
            return cache_[92];
        }

        virtual bool le_audio_support_unidirectional_voice_assistant() override {
            if (cache_[93] == -1) {
                cache_[93] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.le_audio_support_unidirectional_voice_assistant",
                    "false") == "true";
            }
            return cache_[93];
        }

        virtual bool le_periodic_scanning_reassembler() override {
            if (cache_[94] == -1) {
                cache_[94] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.le_periodic_scanning_reassembler",
                    "true") == "true";
            }
            return cache_[94];
        }

        virtual bool le_scan_fix_remote_exception() override {
            if (cache_[95] == -1) {
                cache_[95] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.le_scan_fix_remote_exception",
                    "true") == "true";
            }
            return cache_[95];
        }

        virtual bool le_scan_use_address_type() override {
            if (cache_[96] == -1) {
                cache_[96] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.le_scan_use_address_type",
                    "false") == "true";
            }
            return cache_[96];
        }

        virtual bool le_scan_use_uid_for_importance() override {
            if (cache_[97] == -1) {
                cache_[97] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.le_scan_use_uid_for_importance",
                    "true") == "true";
            }
            return cache_[97];
        }

        virtual bool leaudio_active_device_manager_group_handling_fix() override {
            if (cache_[98] == -1) {
                cache_[98] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_active_device_manager_group_handling_fix",
                    "true") == "true";
            }
            return cache_[98];
        }

        virtual bool leaudio_add_sampling_frequencies() override {
            if (cache_[99] == -1) {
                cache_[99] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_add_sampling_frequencies",
                    "true") == "true";
            }
            return cache_[99];
        }

        virtual bool leaudio_allow_leaudio_only_devices() override {
            if (cache_[100] == -1) {
                cache_[100] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_allow_leaudio_only_devices",
                    "false") == "true";
            }
            return cache_[100];
        }

        virtual bool leaudio_allowed_context_mask() override {
            if (cache_[101] == -1) {
                cache_[101] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_allowed_context_mask",
                    "false") == "true";
            }
            return cache_[101];
        }

        virtual bool leaudio_api_synchronized_block_fix() override {
            if (cache_[102] == -1) {
                cache_[102] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_api_synchronized_block_fix",
                    "true") == "true";
            }
            return cache_[102];
        }

        virtual bool leaudio_big_depends_on_audio_state() override {
            if (cache_[103] == -1) {
                cache_[103] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_big_depends_on_audio_state",
                    "false") == "true";
            }
            return cache_[103];
        }

        virtual bool leaudio_broadcast_assistant_handle_command_statuses() override {
            if (cache_[104] == -1) {
                cache_[104] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_broadcast_assistant_handle_command_statuses",
                    "true") == "true";
            }
            return cache_[104];
        }

        virtual bool leaudio_broadcast_assistant_peripheral_entrustment() override {
            if (cache_[105] == -1) {
                cache_[105] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_broadcast_assistant_peripheral_entrustment",
                    "false") == "true";
            }
            return cache_[105];
        }

        virtual bool leaudio_broadcast_audio_handover_policies() override {
            if (cache_[106] == -1) {
                cache_[106] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_broadcast_audio_handover_policies",
                    "true") == "true";
            }
            return cache_[106];
        }

        virtual bool leaudio_broadcast_destroy_after_timeout() override {
            if (cache_[107] == -1) {
                cache_[107] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_broadcast_destroy_after_timeout",
                    "false") == "true";
            }
            return cache_[107];
        }

        virtual bool leaudio_broadcast_extract_periodic_scanner_from_state_machine() override {
            if (cache_[108] == -1) {
                cache_[108] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_broadcast_extract_periodic_scanner_from_state_machine",
                    "false") == "true";
            }
            return cache_[108];
        }

        virtual bool leaudio_broadcast_feature_support() override {
            if (cache_[109] == -1) {
                cache_[109] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_broadcast_feature_support",
                    "true") == "true";
            }
            return cache_[109];
        }

        virtual bool leaudio_broadcast_monitor_source_sync_status() override {
            if (cache_[110] == -1) {
                cache_[110] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_broadcast_monitor_source_sync_status",
                    "true") == "true";
            }
            return cache_[110];
        }

        virtual bool leaudio_broadcast_stop_on_streaming_request() override {
            if (cache_[111] == -1) {
                cache_[111] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_broadcast_stop_on_streaming_request",
                    "false") == "true";
            }
            return cache_[111];
        }

        virtual bool leaudio_broadcast_volume_control_for_connected_devices() override {
            if (cache_[112] == -1) {
                cache_[112] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_broadcast_volume_control_for_connected_devices",
                    "true") == "true";
            }
            return cache_[112];
        }

        virtual bool leaudio_broadcast_volume_control_with_set_volume() override {
            if (cache_[113] == -1) {
                cache_[113] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_broadcast_volume_control_with_set_volume",
                    "false") == "true";
            }
            return cache_[113];
        }

        virtual bool leaudio_callback_on_group_stream_status() override {
            if (cache_[114] == -1) {
                cache_[114] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_callback_on_group_stream_status",
                    "true") == "true";
            }
            return cache_[114];
        }

        virtual bool leaudio_codec_config_callback_order_fix() override {
            if (cache_[115] == -1) {
                cache_[115] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_codec_config_callback_order_fix",
                    "false") == "true";
            }
            return cache_[115];
        }

        virtual bool leaudio_dynamic_spatial_audio() override {
            if (cache_[116] == -1) {
                cache_[116] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_dynamic_spatial_audio",
                    "true") == "true";
            }
            return cache_[116];
        }

        virtual bool leaudio_enable_health_based_actions() override {
            if (cache_[117] == -1) {
                cache_[117] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_enable_health_based_actions",
                    "true") == "true";
            }
            return cache_[117];
        }

        virtual bool leaudio_getting_active_state_support() override {
            if (cache_[118] == -1) {
                cache_[118] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_getting_active_state_support",
                    "false") == "true";
            }
            return cache_[118];
        }

        virtual bool leaudio_hal_client_asrc() override {
            if (cache_[119] == -1) {
                cache_[119] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_hal_client_asrc",
                    "true") == "true";
            }
            return cache_[119];
        }

        virtual bool leaudio_mcs_tbs_authorization_rebond_fix() override {
            if (cache_[120] == -1) {
                cache_[120] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_mcs_tbs_authorization_rebond_fix",
                    "true") == "true";
            }
            return cache_[120];
        }

        virtual bool leaudio_mono_location_errata() override {
            if (cache_[121] == -1) {
                cache_[121] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_mono_location_errata",
                    "false") == "true";
            }
            return cache_[121];
        }

        virtual bool leaudio_multicodec_aidl_support() override {
            if (cache_[122] == -1) {
                cache_[122] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_multicodec_aidl_support",
                    "false") == "true";
            }
            return cache_[122];
        }

        virtual bool leaudio_multiple_vocs_instances_api() override {
            if (cache_[123] == -1) {
                cache_[123] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_multiple_vocs_instances_api",
                    "true") == "true";
            }
            return cache_[123];
        }

        virtual bool leaudio_no_context_validate_streaming_request() override {
            if (cache_[124] == -1) {
                cache_[124] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_no_context_validate_streaming_request",
                    "false") == "true";
            }
            return cache_[124];
        }

        virtual bool leaudio_quick_leaudio_toggle_switch_fix() override {
            if (cache_[125] == -1) {
                cache_[125] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_quick_leaudio_toggle_switch_fix",
                    "true") == "true";
            }
            return cache_[125];
        }

        virtual bool leaudio_resume_active_after_hfp_handover() override {
            if (cache_[126] == -1) {
                cache_[126] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_resume_active_after_hfp_handover",
                    "true") == "true";
            }
            return cache_[126];
        }

        virtual bool leaudio_start_request_state_mutex_check() override {
            if (cache_[127] == -1) {
                cache_[127] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_start_request_state_mutex_check",
                    "false") == "true";
            }
            return cache_[127];
        }

        virtual bool leaudio_start_stream_race_fix() override {
            if (cache_[128] == -1) {
                cache_[128] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_start_stream_race_fix",
                    "true") == "true";
            }
            return cache_[128];
        }

        virtual bool leaudio_synchronize_start() override {
            if (cache_[129] == -1) {
                cache_[129] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_synchronize_start",
                    "false") == "true";
            }
            return cache_[129];
        }

        virtual bool leaudio_unicast_inactivate_device_based_on_context() override {
            if (cache_[130] == -1) {
                cache_[130] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_unicast_inactivate_device_based_on_context",
                    "true") == "true";
            }
            return cache_[130];
        }

        virtual bool leaudio_use_audio_mode_listener() override {
            if (cache_[131] == -1) {
                cache_[131] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_use_audio_mode_listener",
                    "false") == "true";
            }
            return cache_[131];
        }

        virtual bool leaudio_volume_change_on_ringtone_fix() override {
            if (cache_[132] == -1) {
                cache_[132] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.leaudio_volume_change_on_ringtone_fix",
                    "true") == "true";
            }
            return cache_[132];
        }

        virtual bool load_did_config_from_sysprops() override {
            if (cache_[133] == -1) {
                cache_[133] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.load_did_config_from_sysprops",
                    "true") == "true";
            }
            return cache_[133];
        }

        virtual bool map_limit_notification() override {
            if (cache_[134] == -1) {
                cache_[134] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.map_limit_notification",
                    "false") == "true";
            }
            return cache_[134];
        }

        virtual bool mcp_allow_play_without_active_player() override {
            if (cache_[135] == -1) {
                cache_[135] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.mcp_allow_play_without_active_player",
                    "false") == "true";
            }
            return cache_[135];
        }

        virtual bool metadata_api_inactive_audio_device_upon_connection() override {
            if (cache_[136] == -1) {
                cache_[136] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.metadata_api_inactive_audio_device_upon_connection",
                    "true") == "true";
            }
            return cache_[136];
        }

        virtual bool mfi_has_uuid() override {
            if (cache_[137] == -1) {
                cache_[137] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.mfi_has_uuid",
                    "true") == "true";
            }
            return cache_[137];
        }

        virtual bool msft_addr_tracking_quirk() override {
            if (cache_[138] == -1) {
                cache_[138] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.msft_addr_tracking_quirk",
                    "false") == "true";
            }
            return cache_[138];
        }

        virtual bool nrpa_non_connectable_adv() override {
            if (cache_[139] == -1) {
                cache_[139] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.nrpa_non_connectable_adv",
                    "false") == "true";
            }
            return cache_[139];
        }

        virtual bool opp_fix_multiple_notifications_issues() override {
            if (cache_[140] == -1) {
                cache_[140] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.opp_fix_multiple_notifications_issues",
                    "true") == "true";
            }
            return cache_[140];
        }

        virtual bool opp_ignore_content_observer_after_service_stop() override {
            if (cache_[141] == -1) {
                cache_[141] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.opp_ignore_content_observer_after_service_stop",
                    "false") == "true";
            }
            return cache_[141];
        }

        virtual bool opp_start_activity_directly_from_notification() override {
            if (cache_[142] == -1) {
                cache_[142] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.opp_start_activity_directly_from_notification",
                    "true") == "true";
            }
            return cache_[142];
        }

        virtual bool pairing_on_unknown_transport() override {
            if (cache_[143] == -1) {
                cache_[143] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.pairing_on_unknown_transport",
                    "true") == "true";
            }
            return cache_[143];
        }

        virtual bool phy_to_native() override {
            if (cache_[144] == -1) {
                cache_[144] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.phy_to_native",
                    "false") == "true";
            }
            return cache_[144];
        }

        virtual bool pretend_network_service() override {
            if (cache_[145] == -1) {
                cache_[145] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.pretend_network_service",
                    "true") == "true";
            }
            return cache_[145];
        }

        virtual bool prevent_hogp_reconnect_when_connected() override {
            if (cache_[146] == -1) {
                cache_[146] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.prevent_hogp_reconnect_when_connected",
                    "true") == "true";
            }
            return cache_[146];
        }

        virtual bool randomize_device_level_media_ids() override {
            if (cache_[147] == -1) {
                cache_[147] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.randomize_device_level_media_ids",
                    "false") == "true";
            }
            return cache_[147];
        }

        virtual bool read_model_num_fix() override {
            if (cache_[148] == -1) {
                cache_[148] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.read_model_num_fix",
                    "true") == "true";
            }
            return cache_[148];
        }

        virtual bool remove_address_map_on_unbond() override {
            if (cache_[149] == -1) {
                cache_[149] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.remove_address_map_on_unbond",
                    "true") == "true";
            }
            return cache_[149];
        }

        virtual bool reset_after_collision() override {
            if (cache_[150] == -1) {
                cache_[150] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.reset_after_collision",
                    "true") == "true";
            }
            return cache_[150];
        }

        virtual bool reset_ag_state_on_collision() override {
            if (cache_[151] == -1) {
                cache_[151] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.reset_ag_state_on_collision",
                    "false") == "true";
            }
            return cache_[151];
        }

        virtual bool reset_pairing_only_for_related_service_discovery() override {
            if (cache_[152] == -1) {
                cache_[152] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.reset_pairing_only_for_related_service_discovery",
                    "true") == "true";
            }
            return cache_[152];
        }

        virtual bool respect_ble_scan_setting() override {
            if (cache_[153] == -1) {
                cache_[153] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.respect_ble_scan_setting",
                    "false") == "true";
            }
            return cache_[153];
        }

        virtual bool retry_esco_with_zero_retransmission_effort() override {
            if (cache_[154] == -1) {
                cache_[154] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.retry_esco_with_zero_retransmission_effort",
                    "false") == "true";
            }
            return cache_[154];
        }

        virtual bool rfcomm_always_use_mitm() override {
            if (cache_[155] == -1) {
                cache_[155] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.rfcomm_always_use_mitm",
                    "false") == "true";
            }
            return cache_[155];
        }

        virtual bool rfcomm_bypass_post_to_main() override {
            if (cache_[156] == -1) {
                cache_[156] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.rfcomm_bypass_post_to_main",
                    "false") == "true";
            }
            return cache_[156];
        }

        virtual bool rnr_present_during_service_discovery() override {
            if (cache_[157] == -1) {
                cache_[157] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.rnr_present_during_service_discovery",
                    "true") == "true";
            }
            return cache_[157];
        }

        virtual bool rnr_reset_state_at_cancel() override {
            if (cache_[158] == -1) {
                cache_[158] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.rnr_reset_state_at_cancel",
                    "true") == "true";
            }
            return cache_[158];
        }

        virtual bool rnr_store_device_type() override {
            if (cache_[159] == -1) {
                cache_[159] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.rnr_store_device_type",
                    "false") == "true";
            }
            return cache_[159];
        }

        virtual bool rnr_validate_page_scan_repetition_mode() override {
            if (cache_[160] == -1) {
                cache_[160] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.rnr_validate_page_scan_repetition_mode",
                    "false") == "true";
            }
            return cache_[160];
        }

        virtual bool run_ble_audio_ticks_in_worker_thread() override {
            if (cache_[161] == -1) {
                cache_[161] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.run_ble_audio_ticks_in_worker_thread",
                    "false") == "true";
            }
            return cache_[161];
        }

        virtual bool run_clock_recovery_in_worker_thread() override {
            if (cache_[162] == -1) {
                cache_[162] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.run_clock_recovery_in_worker_thread",
                    "false") == "true";
            }
            return cache_[162];
        }

        virtual bool save_initial_hid_connection_policy() override {
            if (cache_[163] == -1) {
                cache_[163] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.save_initial_hid_connection_policy",
                    "true") == "true";
            }
            return cache_[163];
        }

        virtual bool scan_manager_refactor() override {
            if (cache_[164] == -1) {
                cache_[164] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.scan_manager_refactor",
                    "false") == "true";
            }
            return cache_[164];
        }

        virtual bool scan_record_manufacturer_data_merge() override {
            if (cache_[165] == -1) {
                cache_[165] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.scan_record_manufacturer_data_merge",
                    "false") == "true";
            }
            return cache_[165];
        }

        virtual bool sec_dont_clear_keys_on_encryption_err() override {
            if (cache_[166] == -1) {
                cache_[166] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.sec_dont_clear_keys_on_encryption_err",
                    "false") == "true";
            }
            return cache_[166];
        }

        virtual bool separate_service_and_device_discovery() override {
            if (cache_[167] == -1) {
                cache_[167] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.separate_service_and_device_discovery",
                    "true") == "true";
            }
            return cache_[167];
        }

        virtual bool settings_can_control_hap_preset() override {
            if (cache_[168] == -1) {
                cache_[168] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.settings_can_control_hap_preset",
                    "true") == "true";
            }
            return cache_[168];
        }

        virtual bool sink_audio_policy_handover() override {
            if (cache_[169] == -1) {
                cache_[169] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.sink_audio_policy_handover",
                    "true") == "true";
            }
            return cache_[169];
        }

        virtual bool skip_unknown_robust_caching() override {
            if (cache_[170] == -1) {
                cache_[170] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.skip_unknown_robust_caching",
                    "false") == "true";
            }
            return cache_[170];
        }

        virtual bool stack_sdp_detect_nil_property_type() override {
            if (cache_[171] == -1) {
                cache_[171] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.stack_sdp_detect_nil_property_type",
                    "false") == "true";
            }
            return cache_[171];
        }

        virtual bool stack_sdp_disconnect_when_cancel_in_pending_state() override {
            if (cache_[172] == -1) {
                cache_[172] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.stack_sdp_disconnect_when_cancel_in_pending_state",
                    "false") == "true";
            }
            return cache_[172];
        }

        virtual bool support_exclusive_manager() override {
            if (cache_[173] == -1) {
                cache_[173] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.support_exclusive_manager",
                    "true") == "true";
            }
            return cache_[173];
        }

        virtual bool support_metadata_device_types_apis() override {
            if (cache_[174] == -1) {
                cache_[174] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.support_metadata_device_types_apis",
                    "false") == "true";
            }
            return cache_[174];
        }

        virtual bool suppress_hid_rejection_broadcast() override {
            if (cache_[175] == -1) {
                cache_[175] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.suppress_hid_rejection_broadcast",
                    "false") == "true";
            }
            return cache_[175];
        }

        virtual bool synchronous_bta_sec() override {
            if (cache_[176] == -1) {
                cache_[176] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.synchronous_bta_sec",
                    "true") == "true";
            }
            return cache_[176];
        }

        virtual bool system_server_messenger() override {
            if (cache_[177] == -1) {
                cache_[177] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.system_server_messenger",
                    "false") == "true";
            }
            return cache_[177];
        }

        virtual bool temporary_pairing_device_properties() override {
            if (cache_[178] == -1) {
                cache_[178] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.temporary_pairing_device_properties",
                    "true") == "true";
            }
            return cache_[178];
        }

        virtual bool uncache_player_when_browsed_player_changes() override {
            if (cache_[179] == -1) {
                cache_[179] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.uncache_player_when_browsed_player_changes",
                    "false") == "true";
            }
            return cache_[179];
        }

        virtual bool unix_file_socket_creation_failure() override {
            if (cache_[180] == -1) {
                cache_[180] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.unix_file_socket_creation_failure",
                    "true") == "true";
            }
            return cache_[180];
        }

        virtual bool update_inquiry_result_on_flag_change() override {
            if (cache_[181] == -1) {
                cache_[181] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.update_inquiry_result_on_flag_change",
                    "true") == "true";
            }
            return cache_[181];
        }

        virtual bool use_dsp_codec_when_controller_does_not_support() override {
            if (cache_[182] == -1) {
                cache_[182] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.use_dsp_codec_when_controller_does_not_support",
                    "true") == "true";
            }
            return cache_[182];
        }

        virtual bool use_entire_message_handle() override {
            if (cache_[183] == -1) {
                cache_[183] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.use_entire_message_handle",
                    "false") == "true";
            }
            return cache_[183];
        }

        virtual bool use_le_shim_connection_map_guard() override {
            if (cache_[184] == -1) {
                cache_[184] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.use_le_shim_connection_map_guard",
                    "false") == "true";
            }
            return cache_[184];
        }

        virtual bool use_local_oob_extended_command() override {
            if (cache_[185] == -1) {
                cache_[185] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.use_local_oob_extended_command",
                    "false") == "true";
            }
            return cache_[185];
        }

        virtual bool vcp_mute_unmute() override {
            if (cache_[186] == -1) {
                cache_[186] = server_configurable_flags::GetServerConfigurableFlag(
                    "aconfig_flags.bluetooth",
                    "com.android.bluetooth.flags.vcp_mute_unmute",
                    "false") == "true";
            }
            return cache_[186];
        }
    private:
        std::vector<int8_t> cache_ = std::vector<int8_t>(187, -1);
    };

std::unique_ptr<flag_provider_interface> provider_ =
    std::make_unique<flag_provider>();
}


bool com_android_bluetooth_flags_a2dp_async_allow_low_latency() {
    return com::android::bluetooth::flags::a2dp_async_allow_low_latency();
}

bool com_android_bluetooth_flags_a2dp_concurrent_source_sink() {
    return com::android::bluetooth::flags::a2dp_concurrent_source_sink();
}

bool com_android_bluetooth_flags_a2dp_ignore_started_when_responder() {
    return com::android::bluetooth::flags::a2dp_ignore_started_when_responder();
}

bool com_android_bluetooth_flags_a2dp_offload_codec_extensibility() {
    return com::android::bluetooth::flags::a2dp_offload_codec_extensibility();
}

bool com_android_bluetooth_flags_a2dp_service_looper() {
    return com::android::bluetooth::flags::a2dp_service_looper();
}

bool com_android_bluetooth_flags_abs_volume_sdp_conflict() {
    return com::android::bluetooth::flags::abs_volume_sdp_conflict();
}

bool com_android_bluetooth_flags_airplane_mode_x_ble_on() {
    return com::android::bluetooth::flags::airplane_mode_x_ble_on();
}

bool com_android_bluetooth_flags_allow_switching_hid_and_hogp() {
    return com::android::bluetooth::flags::allow_switching_hid_and_hogp();
}

bool com_android_bluetooth_flags_android_headtracker_service() {
    return com::android::bluetooth::flags::android_headtracker_service();
}

bool com_android_bluetooth_flags_api_get_connection_state_using_identity_address() {
    return com::android::bluetooth::flags::api_get_connection_state_using_identity_address();
}

bool com_android_bluetooth_flags_asha_asrc() {
    return com::android::bluetooth::flags::asha_asrc();
}

bool com_android_bluetooth_flags_asymmetric_phy_for_unidirectional_cis() {
    return com::android::bluetooth::flags::asymmetric_phy_for_unidirectional_cis();
}

bool com_android_bluetooth_flags_audio_port_binder_inherit_rt() {
    return com::android::bluetooth::flags::audio_port_binder_inherit_rt();
}

bool com_android_bluetooth_flags_audio_routing_centralization() {
    return com::android::bluetooth::flags::audio_routing_centralization();
}

bool com_android_bluetooth_flags_auto_connect_on_hfp_when_no_a2dp_device() {
    return com::android::bluetooth::flags::auto_connect_on_hfp_when_no_a2dp_device();
}

bool com_android_bluetooth_flags_auto_connect_on_multiple_hfp_when_no_a2dp_device() {
    return com::android::bluetooth::flags::auto_connect_on_multiple_hfp_when_no_a2dp_device();
}

bool com_android_bluetooth_flags_auto_on_feature() {
    return com::android::bluetooth::flags::auto_on_feature();
}

bool com_android_bluetooth_flags_avdtp_error_codes() {
    return com::android::bluetooth::flags::avdtp_error_codes();
}

bool com_android_bluetooth_flags_avoid_static_loading_of_native() {
    return com::android::bluetooth::flags::avoid_static_loading_of_native();
}

bool com_android_bluetooth_flags_avrcp_connect_a2dp_delayed() {
    return com::android::bluetooth::flags::avrcp_connect_a2dp_delayed();
}

bool com_android_bluetooth_flags_avrcp_sdp_records() {
    return com::android::bluetooth::flags::avrcp_sdp_records();
}

bool com_android_bluetooth_flags_ble_check_data_length_on_legacy_advertising() {
    return com::android::bluetooth::flags::ble_check_data_length_on_legacy_advertising();
}

bool com_android_bluetooth_flags_ble_context_map_remove_fix() {
    return com::android::bluetooth::flags::ble_context_map_remove_fix();
}

bool com_android_bluetooth_flags_ble_gatt_server_use_address_type_in_connection() {
    return com::android::bluetooth::flags::ble_gatt_server_use_address_type_in_connection();
}

bool com_android_bluetooth_flags_ble_scan_adv_metrics_redesign() {
    return com::android::bluetooth::flags::ble_scan_adv_metrics_redesign();
}

bool com_android_bluetooth_flags_bluetooth_power_telemetry() {
    return com::android::bluetooth::flags::bluetooth_power_telemetry();
}

bool com_android_bluetooth_flags_bluffs_mitigation() {
    return com::android::bluetooth::flags::bluffs_mitigation();
}

bool com_android_bluetooth_flags_bond_transport_after_bond_cancel_fix() {
    return com::android::bluetooth::flags::bond_transport_after_bond_cancel_fix();
}

bool com_android_bluetooth_flags_break_uhid_polling_early() {
    return com::android::bluetooth::flags::break_uhid_polling_early();
}

bool com_android_bluetooth_flags_browsing_refactor() {
    return com::android::bluetooth::flags::browsing_refactor();
}

bool com_android_bluetooth_flags_bt_socket_api_l2cap_cid() {
    return com::android::bluetooth::flags::bt_socket_api_l2cap_cid();
}

bool com_android_bluetooth_flags_bt_system_context_report() {
    return com::android::bluetooth::flags::bt_system_context_report();
}

bool com_android_bluetooth_flags_bta_ag_cmd_brsf_allow_uint32() {
    return com::android::bluetooth::flags::bta_ag_cmd_brsf_allow_uint32();
}

bool com_android_bluetooth_flags_bta_av_setconfig_rej_type_confusion() {
    return com::android::bluetooth::flags::bta_av_setconfig_rej_type_confusion();
}

bool com_android_bluetooth_flags_bta_av_use_peer_codec() {
    return com::android::bluetooth::flags::bta_av_use_peer_codec();
}

bool com_android_bluetooth_flags_bta_dm_defer_device_discovery_state_change_until_rnr_complete() {
    return com::android::bluetooth::flags::bta_dm_defer_device_discovery_state_change_until_rnr_complete();
}

bool com_android_bluetooth_flags_bta_dm_disc_stuck_in_cancelling_fix() {
    return com::android::bluetooth::flags::bta_dm_disc_stuck_in_cancelling_fix();
}

bool com_android_bluetooth_flags_bta_dm_discover_both() {
    return com::android::bluetooth::flags::bta_dm_discover_both();
}

bool com_android_bluetooth_flags_cancel_pairing_only_on_disconnected_transport() {
    return com::android::bluetooth::flags::cancel_pairing_only_on_disconnected_transport();
}

bool com_android_bluetooth_flags_channel_sounding() {
    return com::android::bluetooth::flags::channel_sounding();
}

bool com_android_bluetooth_flags_channel_sounding_in_stack() {
    return com::android::bluetooth::flags::channel_sounding_in_stack();
}

bool com_android_bluetooth_flags_cleanup_le_only_device_type() {
    return com::android::bluetooth::flags::cleanup_le_only_device_type();
}

bool com_android_bluetooth_flags_clear_collision_state_on_pairing_complete() {
    return com::android::bluetooth::flags::clear_collision_state_on_pairing_complete();
}

bool com_android_bluetooth_flags_close_rfcomm_instead_of_reset() {
    return com::android::bluetooth::flags::close_rfcomm_instead_of_reset();
}

bool com_android_bluetooth_flags_connect_hid_after_service_discovery() {
    return com::android::bluetooth::flags::connect_hid_after_service_discovery();
}

bool com_android_bluetooth_flags_continue_service_discovery_when_cancel_device_discovery() {
    return com::android::bluetooth::flags::continue_service_discovery_when_cancel_device_discovery();
}

bool com_android_bluetooth_flags_correct_bond_type_of_loaded_devices() {
    return com::android::bluetooth::flags::correct_bond_type_of_loaded_devices();
}

bool com_android_bluetooth_flags_device_iot_config_logging() {
    return com::android::bluetooth::flags::device_iot_config_logging();
}

bool com_android_bluetooth_flags_divide_long_single_gap_data() {
    return com::android::bluetooth::flags::divide_long_single_gap_data();
}

bool com_android_bluetooth_flags_do_not_replace_existing_cod_with_uncategorized_cod() {
    return com::android::bluetooth::flags::do_not_replace_existing_cod_with_uncategorized_cod();
}

bool com_android_bluetooth_flags_dumpsys_acquire_stack_when_executing() {
    return com::android::bluetooth::flags::dumpsys_acquire_stack_when_executing();
}

bool com_android_bluetooth_flags_enable_hap_by_default() {
    return com::android::bluetooth::flags::enable_hap_by_default();
}

bool com_android_bluetooth_flags_enable_sniff_offload() {
    return com::android::bluetooth::flags::enable_sniff_offload();
}

bool com_android_bluetooth_flags_encrypted_advertising_data() {
    return com::android::bluetooth::flags::encrypted_advertising_data();
}

bool com_android_bluetooth_flags_ensure_valid_adv_flag() {
    return com::android::bluetooth::flags::ensure_valid_adv_flag();
}

bool com_android_bluetooth_flags_enumerate_gatt_errors() {
    return com::android::bluetooth::flags::enumerate_gatt_errors();
}

bool com_android_bluetooth_flags_explicit_kill_from_system_server() {
    return com::android::bluetooth::flags::explicit_kill_from_system_server();
}

bool com_android_bluetooth_flags_fast_bind_to_app() {
    return com::android::bluetooth::flags::fast_bind_to_app();
}

bool com_android_bluetooth_flags_fix_hfp_qual_1_9() {
    return com::android::bluetooth::flags::fix_hfp_qual_1_9();
}

bool com_android_bluetooth_flags_fix_le_oob_pairing_bypass() {
    return com::android::bluetooth::flags::fix_le_oob_pairing_bypass();
}

bool com_android_bluetooth_flags_fix_le_pairing_passkey_entry_bypass() {
    return com::android::bluetooth::flags::fix_le_pairing_passkey_entry_bypass();
}

bool com_android_bluetooth_flags_fix_nonconnectable_scannable_advertisement() {
    return com::android::bluetooth::flags::fix_nonconnectable_scannable_advertisement();
}

bool com_android_bluetooth_flags_fix_pairing_failure_reason_from_remote() {
    return com::android::bluetooth::flags::fix_pairing_failure_reason_from_remote();
}

bool com_android_bluetooth_flags_floss_separate_host_privacy_and_llprivacy() {
    return com::android::bluetooth::flags::floss_separate_host_privacy_and_llprivacy();
}

bool com_android_bluetooth_flags_force_bredr_for_sdp_retry() {
    return com::android::bluetooth::flags::force_bredr_for_sdp_retry();
}

bool com_android_bluetooth_flags_gatt_cleanup_restricted_handles() {
    return com::android::bluetooth::flags::gatt_cleanup_restricted_handles();
}

bool com_android_bluetooth_flags_gatt_drop_acl_on_out_of_resources_fix() {
    return com::android::bluetooth::flags::gatt_drop_acl_on_out_of_resources_fix();
}

bool com_android_bluetooth_flags_gatt_fix_device_busy() {
    return com::android::bluetooth::flags::gatt_fix_device_busy();
}

bool com_android_bluetooth_flags_gatt_reconnect_on_bt_on_fix() {
    return com::android::bluetooth::flags::gatt_reconnect_on_bt_on_fix();
}

bool com_android_bluetooth_flags_gatt_rediscover_on_canceled() {
    return com::android::bluetooth::flags::gatt_rediscover_on_canceled();
}

bool com_android_bluetooth_flags_gdx_device_discovery() {
    return com::android::bluetooth::flags::gdx_device_discovery();
}

bool com_android_bluetooth_flags_gdx_service_discovery() {
    return com::android::bluetooth::flags::gdx_service_discovery();
}

bool com_android_bluetooth_flags_get_address_type_api() {
    return com::android::bluetooth::flags::get_address_type_api();
}

bool com_android_bluetooth_flags_handle_delivery_sending_failure_events() {
    return com::android::bluetooth::flags::handle_delivery_sending_failure_events();
}

bool com_android_bluetooth_flags_headset_client_am_hf_volume_symmetric() {
    return com::android::bluetooth::flags::headset_client_am_hf_volume_symmetric();
}

bool com_android_bluetooth_flags_headtracker_codec_capability() {
    return com::android::bluetooth::flags::headtracker_codec_capability();
}

bool com_android_bluetooth_flags_hfp_codec_aptx_voice() {
    return com::android::bluetooth::flags::hfp_codec_aptx_voice();
}

bool com_android_bluetooth_flags_hid_report_queuing() {
    return com::android::bluetooth::flags::hid_report_queuing();
}

bool com_android_bluetooth_flags_higher_l2cap_flush_threshold() {
    return com::android::bluetooth::flags::higher_l2cap_flush_threshold();
}

bool com_android_bluetooth_flags_identity_address_null_if_unknown() {
    return com::android::bluetooth::flags::identity_address_null_if_unknown();
}

bool com_android_bluetooth_flags_ignore_bond_type_for_le() {
    return com::android::bluetooth::flags::ignore_bond_type_for_le();
}

bool com_android_bluetooth_flags_is_sco_managed_by_audio() {
    return com::android::bluetooth::flags::is_sco_managed_by_audio();
}

bool com_android_bluetooth_flags_keep_hfp_active_during_leaudio_handover() {
    return com::android::bluetooth::flags::keep_hfp_active_during_leaudio_handover();
}

bool com_android_bluetooth_flags_keep_stopped_media_browser_service() {
    return com::android::bluetooth::flags::keep_stopped_media_browser_service();
}

bool com_android_bluetooth_flags_key_missing_as_ordered_broadcast() {
    return com::android::bluetooth::flags::key_missing_as_ordered_broadcast();
}

bool com_android_bluetooth_flags_key_missing_broadcast() {
    return com::android::bluetooth::flags::key_missing_broadcast();
}

bool com_android_bluetooth_flags_key_missing_classic_device() {
    return com::android::bluetooth::flags::key_missing_classic_device();
}

bool com_android_bluetooth_flags_kill_instead_of_exit() {
    return com::android::bluetooth::flags::kill_instead_of_exit();
}

bool com_android_bluetooth_flags_l2cap_le_do_not_adjust_min_interval() {
    return com::android::bluetooth::flags::l2cap_le_do_not_adjust_min_interval();
}

bool com_android_bluetooth_flags_l2cap_p_ccb_check_rewrite() {
    return com::android::bluetooth::flags::l2cap_p_ccb_check_rewrite();
}

bool com_android_bluetooth_flags_l2cap_tx_complete_cb_info() {
    return com::android::bluetooth::flags::l2cap_tx_complete_cb_info();
}

bool com_android_bluetooth_flags_le_audio_base_ecosystem_interval() {
    return com::android::bluetooth::flags::le_audio_base_ecosystem_interval();
}

bool com_android_bluetooth_flags_le_audio_dev_type_detection_fix() {
    return com::android::bluetooth::flags::le_audio_dev_type_detection_fix();
}

bool com_android_bluetooth_flags_le_audio_support_unidirectional_voice_assistant() {
    return com::android::bluetooth::flags::le_audio_support_unidirectional_voice_assistant();
}

bool com_android_bluetooth_flags_le_periodic_scanning_reassembler() {
    return com::android::bluetooth::flags::le_periodic_scanning_reassembler();
}

bool com_android_bluetooth_flags_le_scan_fix_remote_exception() {
    return com::android::bluetooth::flags::le_scan_fix_remote_exception();
}

bool com_android_bluetooth_flags_le_scan_use_address_type() {
    return com::android::bluetooth::flags::le_scan_use_address_type();
}

bool com_android_bluetooth_flags_le_scan_use_uid_for_importance() {
    return com::android::bluetooth::flags::le_scan_use_uid_for_importance();
}

bool com_android_bluetooth_flags_leaudio_active_device_manager_group_handling_fix() {
    return com::android::bluetooth::flags::leaudio_active_device_manager_group_handling_fix();
}

bool com_android_bluetooth_flags_leaudio_add_sampling_frequencies() {
    return com::android::bluetooth::flags::leaudio_add_sampling_frequencies();
}

bool com_android_bluetooth_flags_leaudio_allow_leaudio_only_devices() {
    return com::android::bluetooth::flags::leaudio_allow_leaudio_only_devices();
}

bool com_android_bluetooth_flags_leaudio_allowed_context_mask() {
    return com::android::bluetooth::flags::leaudio_allowed_context_mask();
}

bool com_android_bluetooth_flags_leaudio_api_synchronized_block_fix() {
    return com::android::bluetooth::flags::leaudio_api_synchronized_block_fix();
}

bool com_android_bluetooth_flags_leaudio_big_depends_on_audio_state() {
    return com::android::bluetooth::flags::leaudio_big_depends_on_audio_state();
}

bool com_android_bluetooth_flags_leaudio_broadcast_assistant_handle_command_statuses() {
    return com::android::bluetooth::flags::leaudio_broadcast_assistant_handle_command_statuses();
}

bool com_android_bluetooth_flags_leaudio_broadcast_assistant_peripheral_entrustment() {
    return com::android::bluetooth::flags::leaudio_broadcast_assistant_peripheral_entrustment();
}

bool com_android_bluetooth_flags_leaudio_broadcast_audio_handover_policies() {
    return com::android::bluetooth::flags::leaudio_broadcast_audio_handover_policies();
}

bool com_android_bluetooth_flags_leaudio_broadcast_destroy_after_timeout() {
    return com::android::bluetooth::flags::leaudio_broadcast_destroy_after_timeout();
}

bool com_android_bluetooth_flags_leaudio_broadcast_extract_periodic_scanner_from_state_machine() {
    return com::android::bluetooth::flags::leaudio_broadcast_extract_periodic_scanner_from_state_machine();
}

bool com_android_bluetooth_flags_leaudio_broadcast_feature_support() {
    return com::android::bluetooth::flags::leaudio_broadcast_feature_support();
}

bool com_android_bluetooth_flags_leaudio_broadcast_monitor_source_sync_status() {
    return com::android::bluetooth::flags::leaudio_broadcast_monitor_source_sync_status();
}

bool com_android_bluetooth_flags_leaudio_broadcast_stop_on_streaming_request() {
    return com::android::bluetooth::flags::leaudio_broadcast_stop_on_streaming_request();
}

bool com_android_bluetooth_flags_leaudio_broadcast_volume_control_for_connected_devices() {
    return com::android::bluetooth::flags::leaudio_broadcast_volume_control_for_connected_devices();
}

bool com_android_bluetooth_flags_leaudio_broadcast_volume_control_with_set_volume() {
    return com::android::bluetooth::flags::leaudio_broadcast_volume_control_with_set_volume();
}

bool com_android_bluetooth_flags_leaudio_callback_on_group_stream_status() {
    return com::android::bluetooth::flags::leaudio_callback_on_group_stream_status();
}

bool com_android_bluetooth_flags_leaudio_codec_config_callback_order_fix() {
    return com::android::bluetooth::flags::leaudio_codec_config_callback_order_fix();
}

bool com_android_bluetooth_flags_leaudio_dynamic_spatial_audio() {
    return com::android::bluetooth::flags::leaudio_dynamic_spatial_audio();
}

bool com_android_bluetooth_flags_leaudio_enable_health_based_actions() {
    return com::android::bluetooth::flags::leaudio_enable_health_based_actions();
}

bool com_android_bluetooth_flags_leaudio_getting_active_state_support() {
    return com::android::bluetooth::flags::leaudio_getting_active_state_support();
}

bool com_android_bluetooth_flags_leaudio_hal_client_asrc() {
    return com::android::bluetooth::flags::leaudio_hal_client_asrc();
}

bool com_android_bluetooth_flags_leaudio_mcs_tbs_authorization_rebond_fix() {
    return com::android::bluetooth::flags::leaudio_mcs_tbs_authorization_rebond_fix();
}

bool com_android_bluetooth_flags_leaudio_mono_location_errata() {
    return com::android::bluetooth::flags::leaudio_mono_location_errata();
}

bool com_android_bluetooth_flags_leaudio_multicodec_aidl_support() {
    return com::android::bluetooth::flags::leaudio_multicodec_aidl_support();
}

bool com_android_bluetooth_flags_leaudio_multiple_vocs_instances_api() {
    return com::android::bluetooth::flags::leaudio_multiple_vocs_instances_api();
}

bool com_android_bluetooth_flags_leaudio_no_context_validate_streaming_request() {
    return com::android::bluetooth::flags::leaudio_no_context_validate_streaming_request();
}

bool com_android_bluetooth_flags_leaudio_quick_leaudio_toggle_switch_fix() {
    return com::android::bluetooth::flags::leaudio_quick_leaudio_toggle_switch_fix();
}

bool com_android_bluetooth_flags_leaudio_resume_active_after_hfp_handover() {
    return com::android::bluetooth::flags::leaudio_resume_active_after_hfp_handover();
}

bool com_android_bluetooth_flags_leaudio_start_request_state_mutex_check() {
    return com::android::bluetooth::flags::leaudio_start_request_state_mutex_check();
}

bool com_android_bluetooth_flags_leaudio_start_stream_race_fix() {
    return com::android::bluetooth::flags::leaudio_start_stream_race_fix();
}

bool com_android_bluetooth_flags_leaudio_synchronize_start() {
    return com::android::bluetooth::flags::leaudio_synchronize_start();
}

bool com_android_bluetooth_flags_leaudio_unicast_inactivate_device_based_on_context() {
    return com::android::bluetooth::flags::leaudio_unicast_inactivate_device_based_on_context();
}

bool com_android_bluetooth_flags_leaudio_use_audio_mode_listener() {
    return com::android::bluetooth::flags::leaudio_use_audio_mode_listener();
}

bool com_android_bluetooth_flags_leaudio_volume_change_on_ringtone_fix() {
    return com::android::bluetooth::flags::leaudio_volume_change_on_ringtone_fix();
}

bool com_android_bluetooth_flags_load_did_config_from_sysprops() {
    return com::android::bluetooth::flags::load_did_config_from_sysprops();
}

bool com_android_bluetooth_flags_map_limit_notification() {
    return com::android::bluetooth::flags::map_limit_notification();
}

bool com_android_bluetooth_flags_mcp_allow_play_without_active_player() {
    return com::android::bluetooth::flags::mcp_allow_play_without_active_player();
}

bool com_android_bluetooth_flags_metadata_api_inactive_audio_device_upon_connection() {
    return com::android::bluetooth::flags::metadata_api_inactive_audio_device_upon_connection();
}

bool com_android_bluetooth_flags_mfi_has_uuid() {
    return com::android::bluetooth::flags::mfi_has_uuid();
}

bool com_android_bluetooth_flags_msft_addr_tracking_quirk() {
    return com::android::bluetooth::flags::msft_addr_tracking_quirk();
}

bool com_android_bluetooth_flags_nrpa_non_connectable_adv() {
    return com::android::bluetooth::flags::nrpa_non_connectable_adv();
}

bool com_android_bluetooth_flags_opp_fix_multiple_notifications_issues() {
    return com::android::bluetooth::flags::opp_fix_multiple_notifications_issues();
}

bool com_android_bluetooth_flags_opp_ignore_content_observer_after_service_stop() {
    return com::android::bluetooth::flags::opp_ignore_content_observer_after_service_stop();
}

bool com_android_bluetooth_flags_opp_start_activity_directly_from_notification() {
    return com::android::bluetooth::flags::opp_start_activity_directly_from_notification();
}

bool com_android_bluetooth_flags_pairing_on_unknown_transport() {
    return com::android::bluetooth::flags::pairing_on_unknown_transport();
}

bool com_android_bluetooth_flags_phy_to_native() {
    return com::android::bluetooth::flags::phy_to_native();
}

bool com_android_bluetooth_flags_pretend_network_service() {
    return com::android::bluetooth::flags::pretend_network_service();
}

bool com_android_bluetooth_flags_prevent_hogp_reconnect_when_connected() {
    return com::android::bluetooth::flags::prevent_hogp_reconnect_when_connected();
}

bool com_android_bluetooth_flags_randomize_device_level_media_ids() {
    return com::android::bluetooth::flags::randomize_device_level_media_ids();
}

bool com_android_bluetooth_flags_read_model_num_fix() {
    return com::android::bluetooth::flags::read_model_num_fix();
}

bool com_android_bluetooth_flags_remove_address_map_on_unbond() {
    return com::android::bluetooth::flags::remove_address_map_on_unbond();
}

bool com_android_bluetooth_flags_reset_after_collision() {
    return com::android::bluetooth::flags::reset_after_collision();
}

bool com_android_bluetooth_flags_reset_ag_state_on_collision() {
    return com::android::bluetooth::flags::reset_ag_state_on_collision();
}

bool com_android_bluetooth_flags_reset_pairing_only_for_related_service_discovery() {
    return com::android::bluetooth::flags::reset_pairing_only_for_related_service_discovery();
}

bool com_android_bluetooth_flags_respect_ble_scan_setting() {
    return com::android::bluetooth::flags::respect_ble_scan_setting();
}

bool com_android_bluetooth_flags_retry_esco_with_zero_retransmission_effort() {
    return com::android::bluetooth::flags::retry_esco_with_zero_retransmission_effort();
}

bool com_android_bluetooth_flags_rfcomm_always_use_mitm() {
    return com::android::bluetooth::flags::rfcomm_always_use_mitm();
}

bool com_android_bluetooth_flags_rfcomm_bypass_post_to_main() {
    return com::android::bluetooth::flags::rfcomm_bypass_post_to_main();
}

bool com_android_bluetooth_flags_rnr_present_during_service_discovery() {
    return com::android::bluetooth::flags::rnr_present_during_service_discovery();
}

bool com_android_bluetooth_flags_rnr_reset_state_at_cancel() {
    return com::android::bluetooth::flags::rnr_reset_state_at_cancel();
}

bool com_android_bluetooth_flags_rnr_store_device_type() {
    return com::android::bluetooth::flags::rnr_store_device_type();
}

bool com_android_bluetooth_flags_rnr_validate_page_scan_repetition_mode() {
    return com::android::bluetooth::flags::rnr_validate_page_scan_repetition_mode();
}

bool com_android_bluetooth_flags_run_ble_audio_ticks_in_worker_thread() {
    return com::android::bluetooth::flags::run_ble_audio_ticks_in_worker_thread();
}

bool com_android_bluetooth_flags_run_clock_recovery_in_worker_thread() {
    return com::android::bluetooth::flags::run_clock_recovery_in_worker_thread();
}

bool com_android_bluetooth_flags_save_initial_hid_connection_policy() {
    return com::android::bluetooth::flags::save_initial_hid_connection_policy();
}

bool com_android_bluetooth_flags_scan_manager_refactor() {
    return com::android::bluetooth::flags::scan_manager_refactor();
}

bool com_android_bluetooth_flags_scan_record_manufacturer_data_merge() {
    return com::android::bluetooth::flags::scan_record_manufacturer_data_merge();
}

bool com_android_bluetooth_flags_sec_dont_clear_keys_on_encryption_err() {
    return com::android::bluetooth::flags::sec_dont_clear_keys_on_encryption_err();
}

bool com_android_bluetooth_flags_separate_service_and_device_discovery() {
    return com::android::bluetooth::flags::separate_service_and_device_discovery();
}

bool com_android_bluetooth_flags_settings_can_control_hap_preset() {
    return com::android::bluetooth::flags::settings_can_control_hap_preset();
}

bool com_android_bluetooth_flags_sink_audio_policy_handover() {
    return com::android::bluetooth::flags::sink_audio_policy_handover();
}

bool com_android_bluetooth_flags_skip_unknown_robust_caching() {
    return com::android::bluetooth::flags::skip_unknown_robust_caching();
}

bool com_android_bluetooth_flags_stack_sdp_detect_nil_property_type() {
    return com::android::bluetooth::flags::stack_sdp_detect_nil_property_type();
}

bool com_android_bluetooth_flags_stack_sdp_disconnect_when_cancel_in_pending_state() {
    return com::android::bluetooth::flags::stack_sdp_disconnect_when_cancel_in_pending_state();
}

bool com_android_bluetooth_flags_support_exclusive_manager() {
    return com::android::bluetooth::flags::support_exclusive_manager();
}

bool com_android_bluetooth_flags_support_metadata_device_types_apis() {
    return com::android::bluetooth::flags::support_metadata_device_types_apis();
}

bool com_android_bluetooth_flags_suppress_hid_rejection_broadcast() {
    return com::android::bluetooth::flags::suppress_hid_rejection_broadcast();
}

bool com_android_bluetooth_flags_synchronous_bta_sec() {
    return com::android::bluetooth::flags::synchronous_bta_sec();
}

bool com_android_bluetooth_flags_system_server_messenger() {
    return com::android::bluetooth::flags::system_server_messenger();
}

bool com_android_bluetooth_flags_temporary_pairing_device_properties() {
    return com::android::bluetooth::flags::temporary_pairing_device_properties();
}

bool com_android_bluetooth_flags_uncache_player_when_browsed_player_changes() {
    return com::android::bluetooth::flags::uncache_player_when_browsed_player_changes();
}

bool com_android_bluetooth_flags_unix_file_socket_creation_failure() {
    return com::android::bluetooth::flags::unix_file_socket_creation_failure();
}

bool com_android_bluetooth_flags_update_inquiry_result_on_flag_change() {
    return com::android::bluetooth::flags::update_inquiry_result_on_flag_change();
}

bool com_android_bluetooth_flags_use_dsp_codec_when_controller_does_not_support() {
    return com::android::bluetooth::flags::use_dsp_codec_when_controller_does_not_support();
}

bool com_android_bluetooth_flags_use_entire_message_handle() {
    return com::android::bluetooth::flags::use_entire_message_handle();
}

bool com_android_bluetooth_flags_use_le_shim_connection_map_guard() {
    return com::android::bluetooth::flags::use_le_shim_connection_map_guard();
}

bool com_android_bluetooth_flags_use_local_oob_extended_command() {
    return com::android::bluetooth::flags::use_local_oob_extended_command();
}

bool com_android_bluetooth_flags_vcp_mute_unmute() {
    return com::android::bluetooth::flags::vcp_mute_unmute();
}



