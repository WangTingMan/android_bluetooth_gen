#pragma once
#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <iterator>
#include <new>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

namespace bluetooth {
namespace common {
namespace init_flags {

    struct InitFlagWithValue final
    {
        ::std::string flag;
        ::std::string value;
        using IsRelocatable = ::std::true_type;
    };

void load(::std::vector<::std::string> flags) noexcept;

void set_all_for_testing() noexcept;

::std::vector<::bluetooth::common::init_flags::InitFlagWithValue> dump() noexcept;

bool always_send_services_if_gatt_disc_done_is_enabled() noexcept;

bool always_use_private_gatt_for_debugging_is_enabled() noexcept;

bool bluetooth_power_telemetry_is_enabled() noexcept;

bool btm_dm_flush_discovery_queue_on_search_cancel_is_enabled() noexcept;

bool classic_discovery_only_is_enabled() noexcept;

bool device_iot_config_logging_is_enabled() noexcept;

bool dynamic_avrcp_version_enhancement_is_enabled() noexcept;

bool gatt_robust_caching_server_is_enabled() noexcept;

::std::int32_t get_hci_adapter() noexcept;

::std::int32_t get_asha_packet_drop_frequency_threshold() noexcept;

::std::int32_t get_asha_phy_update_retry_limit() noexcept;

bool hfp_dynamic_version_is_enabled() noexcept;

bool irk_rotation_is_enabled() noexcept;

bool leaudio_targeted_announcement_reconnection_mode_is_enabled() noexcept;

bool pbap_pse_dynamic_version_upgrade_is_enabled() noexcept;

bool redact_log_is_enabled() noexcept;

bool sco_codec_select_lc3_is_enabled() noexcept;

bool sco_codec_timeout_clear_is_enabled() noexcept;

bool sdp_serialization_is_enabled() noexcept;

bool sdp_skip_rnr_if_known_is_enabled() noexcept;

bool bluetooth_quality_report_callback_is_enabled() noexcept;

bool set_min_encryption_is_enabled() noexcept;

bool subrating_is_enabled() noexcept;

bool use_unified_connection_manager_is_enabled() noexcept;

bool sdp_return_classic_services_when_le_discovery_fails_is_enabled() noexcept;

bool use_rsi_from_cached_inqiry_results_is_enabled() noexcept;

::std::int32_t get_att_mtu_default() noexcept;

bool encryption_in_busy_state_is_enabled() noexcept;
} // namespace init_flags
} // namespace common
} // namespace bluetooth
